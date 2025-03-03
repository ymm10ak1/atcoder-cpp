// {{{
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;
// }}}

int main(){
    int n; cin >> n;
    vector<ll> l(n), r(n);
    rep(i,n) cin >> l[i] >> r[i];
    ll sum = 0;
    rep(i,n) sum += l[i];
    vector<ll> ans(n);
    if(sum <= 0){
        // ソートする必要ないので nr はいらない
        vector<pair<ll,int>> nr;
        rep(i,n) nr.emplace_back(r[i],i);
        sort(all(nr));
        rep(i,n){
            auto [_, j] = nr[i];
            if(sum == 0){
                ans[j] = l[j];
                continue;
            }
            if(r[j]-l[j] >= abs(sum)){
                ans[j] = l[j]+abs(sum);
                sum = 0;
            }else{
                sum += (r[j]-l[j]);
                ans[j] = r[j];
            }
        }
        ll check = 0;
        for(ll x : ans) check += x;
        if(check == 0){
            cout << "Yes" << el;
            rep(i,n) printf("%lld%c", ans[i], i==n-1?'\n':' ');
        }else{
            cout << "No" << el;
        }
        return 0;
    }
    cout << "No" << el;
    return 0;
}
