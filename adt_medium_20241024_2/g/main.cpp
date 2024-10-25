// G
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
    int n, q;
    cin >> n >> q;
    set<int> st;
    int hu = 1;
    rep(i,q){
        int t; cin >> t;
        if(t == 1){
            st.insert(hu++);
        }else if(t == 2){
            int x; cin >> x;
            if(st.count(x) == 1) st.erase(x);
        }else if(t == 3){
            cout << *(st.begin()) << el;
        }
    }
    return 0;
}
