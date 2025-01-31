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
    int n; cin >> n;
    vector<string> a(n);
    rep(i,n) cin >> a[i];
    map<pair<int,int>,pair<int,int>> mp;
    repi(i,1,n) mp[{0,i}] = {0,i-1};
    repi(i,1,n) mp[{i,n-1}] = {i-1,n-1};
    rep(i,n-1) mp[{n-1,i}] = {n-1,i+1};
    rep(i,n-1) mp[{i,0}] = {i+1,0};
    mp[{0,0}] = {1,0};
    rep(i,n)rep(j,n){
        if((i>0 && i<n-1) && (j>0 && j<n-1)) cout << a[i][j];
        else cout << a[mp[{i,j}].first][mp[{i,j}].second];
        if(j == n-1) cout << el;
    }
    return 0;
}
