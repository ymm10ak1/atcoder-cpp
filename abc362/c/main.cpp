// C - Sum = 0
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n; cin >> n;
    vector<ll> l(n), r(n);
    rep(i,n) cin >> l[i] >> r[i];
    vector<ll> ans(n);
    ll d = 0;
    rep(i,n){
        if(l[i]<0 && r[i]<0){
            d += r[i];
            ans[i] = r[i];
        }else if(l[i]>0 && r[i]>0){
            d += l[i];
            ans[i] = l[i];
        }else{
            ans[i] = 0;
        }
    }
    if(d > 0){
        rep(i,n){
            if(d <= 0) break;
            ll ld = l[i]-ans[i];
            if(d+ld <= 0){
                ans[i] -= d;
                d = 0;
            }else if(d+ld > 0){
                ans[i] += ld;
                d += ld;
            }
        }
    }
    if(d < 0){
        rep(i,n){
            if(d >= 0) break;
            ll rd = r[i]-ans[i];
            if(rd+d >= 0){
                ans[i] -= d;
                d = 0;
            }else if(rd+d < 0){
                ans[i] += rd;
                d += rd;
            }
        }
    }
    if(d == 0){
        cout << "Yes" << el;
        rep(i,n) printf("%lld%c", ans[i], i==n-1?'\n':' ');
    }else{
        cout << "No" << el;
    }
    return 0;
}
