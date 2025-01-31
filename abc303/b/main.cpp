// 
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
    vector<vector<int>> a(m,vector<int>(n));
    rep(i,m)rep(j,n){
        cin >> a[i][j];
        a[i][j]--;
    }
    vector<vector<bool>> check(n,vector<bool>(n));
    rep(i,m){
        rep(j,n-1){
            check[a[i][j]][a[i][j+1]] = true;
            check[a[i][j+1]][a[i][j]] = true;
        }
    }
    set<pair<int,int>> st;
    rep(i,n){
        rep(j,n){
            if(i == j) continue;
            if(!check[i][j]){
                int n1 = i, n2 = j;
                if(n1 > n2) swap(n1,n2);
                st.emplace(n1,n2);
            }
        }
    }
    cout << st.size() << el;
    return 0;
}
