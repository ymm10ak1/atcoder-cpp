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

int main(){
    int n; ull k;
    cin >> n >> k;
    ull ans = k*(k+1)/2;
    set<int> st;
    rep(i,n){
        int ai; cin >> ai;
        if(ai<=k && st.count(ai)==0){
            ans -= ai;
            st.insert(ai);
        }
    }
    cout << ans << el;
    return 0;
}
