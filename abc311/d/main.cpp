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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    queue<pair<int,int>> q;
    q.emplace(1,1);
    vector<vector<bool>> visited(n,vector<bool>(m));
    set<pair<int,int>> st;
    visited[1][1] = true;
    while(!q.empty()){
        auto [i,j] = q.front(); q.pop();
        if(st.count({i,j})) continue;
        st.emplace(i,j);
        repi(k,i,n-1){
            visited[k][j] = true;
            if(s[k+1][j] == '#'){
                if(st.count({k,j})) break;
                if(s[k][j] == '#') break;
                q.emplace(k,j);
                break;
            }
        } 
        rrepi(k,i+1,1){
            visited[k][j] = true;
            if(s[k-1][j] == '#'){
                if(st.count({k,j})) break;
                if(s[k][j] == '#') break;
                q.emplace(k,j);
                break;
            }
        }
        repi(k,j,m-1){
            visited[i][k] = true;
            if(s[i][k+1] == '#'){
                if(st.count({i,k})) break;
                if(s[i][k] == '#') break;
                q.emplace(i,k);
                break;
            }
        }
        rrepi(k,j+1,1){
            visited[i][k] = true;
            if(s[i][k-1] == '#'){
                if(st.count({i,k})) break;
                if(s[i][k] == '#') break;
                q.emplace(i,k);
                break;
            }
        }
    }
    int ans = 0;
    rep(i,n)rep(j,m) if(visited[i][j]) ans++;
    cout << ans << el;
    return 0;
}
