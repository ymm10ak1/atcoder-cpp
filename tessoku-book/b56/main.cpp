// B56 - Palindrome Queries
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = n-1; i >= s; --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

const ll MOD = 2147483647;
ll pow100[100010], h1[100010], h2[100010];

ll hash_value(bool first, int l, int r){
    ll v = 0;
    if(first) v = h1[r]-(pow100[r-l+1]*h1[l-1]%MOD);
    else v = h2[r]-(pow100[r-l+1]*h2[l-1]%MOD);
    if(v < 0) v += MOD;
    return v;
}

int main(){
    int n, q;
    string s;
    cin >> n >> q >> s;
    string rs = s;
    reverse(all(rs));
    int t1[n+1], t2[n+1];
    // 文字を数値に変換
    repi(i,1,n+1) t1[i] = (s[i-1]-'a')+1;
    repi(i,1,n+1) t2[i] = (rs[i-1]-'a')+1;
    // 100の1乗, 2乗, ..., n乗を計算
    pow100[0] = 1;
    repi(i,1,n+1) pow100[i] = 100LL*pow100[i-1]%MOD;
    // hash値の計算
    repi(i,1,n+1) h1[i] = (100LL*h1[i-1]+t1[i])%MOD;
    repi(i,1,n+1) h2[i] = (100LL*h2[i-1]+t2[i])%MOD;
    rep(i,q){
        int l, r; cin >> l >> r;
        // s[l,r]のハッシュはh1[r]-(pow100[r-l+1]*h1[l-1]%MOD)で求まる
        ll h1_hash = hash_value(true, l, r);
        // rs[n-r+1,n-l+1]のハッシュはh1[n-l+1]-(pow100[r-l+1]*h1[n-r]%MOD)で求まる
        ll h2_hash = hash_value(false, n-r+1, n-l+1);
        if(h1_hash == h2_hash) cout << "Yes" << el;
        else cout << "No" << el;
    }
    return 0;
}