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
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    vector<int> idx(n);
    rep(i,n) idx[p[i]-1] = i;
    set<int> st;
    rep(i,k) st.insert(idx[i]);
    int ans = (*st.rbegin())-(*st.begin());
    repi(i,k,n){
        st.erase(idx[i-k]);
        st.insert(idx[i]);
        ans = min(ans, (*st.rbegin())-(*st.begin()));
    }
    cout << ans << el;
    return 0;
}
