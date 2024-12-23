// D - Sequence Query
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
    int q; cin >> q;
    multiset<ll> st;
    rep(i,q){
        int t;
        ll x;
        cin >> t >> x;
        if(t == 1){
            st.insert(x);
        }else if(t == 2){
            int k; cin >> k;
            if(k > (int)st.size()){
                cout << -1 << el;
                continue;
            }
            auto it = st.upper_bound(x);
            while(it != st.begin()){
                it--;
                k--;
                if(k == 0) break;
            }
            if(k == 0) cout << *it << el;
            else cout << -1 << el;
        }else if(t == 3){
            int k; cin >> k;
            if(k > (int)st.size()){
                cout << -1 << el;
                continue;
            }
            auto it = st.lower_bound(x);
            while(it != st.end()){
                if(k == 1) break;
                it++;
                k--;
            }
            if(it==st.end() || k > 1) cout << -1 << el;
            else cout << *it << el;
        }
    }
    return 0;
}
