// 
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
    int n, m;
    cin >> n >> m;
    vector<string> s;
    rep(i, n){
        string si; cin >> si;
        s.push_back(si.substr(3, 3));
    }
    set<string> st;
    rep(i, m){
        string ti; cin >> ti;
        st.insert(ti);
    }
    int ans = 0;
    rep(i, n){
        for(auto j : st){
            if(s[i] == j) ++ans;
        }
    }
    cout << ans << el;
    return 0;
}