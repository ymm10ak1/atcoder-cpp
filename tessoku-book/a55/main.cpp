// A55 - Set
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

int main(){
    int q; cin >> q;
    set<int> st;
    rep(i,q){
        int type, x;
        cin >> type >> x;
        if(type == 1){
            st.insert(x);
        }else if(type == 2){
            st.erase(x);
        }else if(type == 3){
            auto it = st.lower_bound(x);
            if(it == st.end()) cout << -1 << el;
            else cout << *it << el;
        }
    }
    return 0;
}