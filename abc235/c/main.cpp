// C - The Kth Time Query
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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    map<int,vector<int>> mp;
    rep(i,n) mp[a[i]].push_back(i+1);
    rep(i,q){
        int x, k;
        cin >> x >> k;
        --k;
        if(mp[x].size() < k+1) cout << -1 << el;
        else cout << mp[x][k] << el;
    }
    return 0;
}
