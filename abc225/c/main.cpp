// C - Calendar Validator
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

bool solve(const vector<vector<int>>& b){
    int n = b.size(), m = b[0].size();
    rep(i,n)rep(j,m-1){
        if(b[i][j]>b[i][j+1] || abs(b[i][j]-b[i][j+1]) != 1) return false;
    }
    rep(i,m)rep(j,n-1){
        if(b[j][i]>b[j+1][i] || abs(b[j][i]-b[j+1][i]) != 7) return false;
    }
    rep(i,n){
        set<int> st;
        rep(j,m) st.insert(b[i][j]/7);
        if(st.size() > 1) return false;
    }
    rep(i,m){
        set<int> st;
        rep(j,n) st.insert(b[j][i]%7);
        if(st.size() > 1) return false;
    }
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> b(n,vector<int>(m));
    rep(i,n)rep(j,m){
        cin >> b[i][j];
        --b[i][j];
    }
    if(solve(b)) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
