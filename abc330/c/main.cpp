// C - Minimize Abs 2
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
    ll d; cin >> d;
    set<ll> st;
    for(ll x=0; x*x<=d; ++x) st.insert(d-x*x);
    ll ans = LLINF;
    for(ll y=1; y*y<=d; ++y){
        ll yy = y*y;
        auto ite = st.lower_bound(yy);
        if(ite != st.end()){
            ans = min(ans, abs((*ite)-yy));
            if(ite != st.begin()){
                --ite;
                ans = min(ans, abs((*ite)-yy));
            }
        }
    }
    cout << ans << el;
    return 0;
}
