// E - Monotonically Increasing
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repi(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i=n-1; i>=s; --i)
#define repli(i, s, n) for(ll i=(s); i<(ll)(n); ++i)
#define repl(i, n) repli(i, 0LL, n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LINF = 1e18;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a;
    rep(i, m) a.push_back(i+1);
    vector<vector<int>> res;
    do{
        bool ok = true;
        vector<int> b;
        rep(i, n) b.push_back(a[i]);
        rep(i, b.size()-1){
            if(b[i]>=b[i+1]) ok = false;
        }
        if(ok) res.push_back(b);
    }while(next_permutation(all(a)));
    map<vector<int>, int> mp;
    rep(i, res.size()){
        if(mp[res[i]] == 0){
            mp[res[i]]++;
            rep(j, res[i].size()){
                cout << res[i][j] << " ";
                if(j == n-1) cout << el;
            }
        }
    }
    return 0;
}