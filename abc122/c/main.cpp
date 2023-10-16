// C - GeT AC
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repi(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i=n-1; i>=s; --i)
#define repli(i, s, n) for(ll i=(s); i<(ll)(n); ++i)
#define repl(i, n) repli(i, 0LL, n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LINF = 1e18;

int main(){
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<int> a(n, 0);
    // "AC"の個数をカウント
    repi(i, 1, n){
        if(s[i-1]=='A' && s[i]=='C') a[i] = 1;
    }
    vector<int> b(n+1, 0);
    rep(i, n) b[i+1] = b[i] + a[i];
    rep(i, q){
        int l, r;
        cin >> l >> r;
        cout << b[r]-b[l] << el;
    }
    return 0;
}