#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    ll n; cin >> n;
    // NOTE: 解説見ると合計がnになる集合の最大値の最小を探すためには二分探索を使う必要はない
    // i(1 <= i <= n)を順に見ていき1~iの和(i*(i+1)/2)がn以上ならnができるらしい
    // この問題はまず1~Xの和がぎりぎりN以上になるXを見つける。このとき1~Xの和とnの差はn未満になっている
    // つまり、1~Xを見て1~Xの和とnの差を無視すればいい
    ll ng = 0, ok = n+1;
    while(abs(ok-ng) > 1){
        ll mid = (ok+ng)/2;
        ll s = (mid-1)*mid/2;
        if(n-mid <= s) ok = mid;
        else ng = mid;
    }
    vector<ll> a;
    for(ll i=1; i<ok; ++i) a.push_back(i);
    vector<ll> s(a.size()+1);
    rep(i,a.size()) s[i+1] = s[i]+a[i];
    int idx = 0;
    rep(i,s.size()){
        if(s[i] >= n-ok){
            idx = i;
            break;
        }
    }
    vector<ll> ans;
    repi(i,1,idx+1){
        if(s[idx]-(n-ok) == i) continue;
        ans.push_back(i);
    }
    ans.push_back(ok);
    sort(all(ans));
    for(ll d : ans) cout << d << el;
    return 0;
}
