// D - レ
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
    vector<int> a(m);
    rep(i, m) cin >> a[i];
    vector<int> v(101, -1);
    rep(i, m){
        v[a[i]] = 1;
    }
    vector<int> tmp;
    vector<vector<int>> ans;
    repi(i, 1, n+1){
        if(v[i] == -1){
            tmp.push_back(i);
            sort(rall(tmp));
            ans.push_back(tmp);
            vector<int> vv;
            tmp = vv;
        }else if(v[i] == 1){
            tmp.push_back(i);
        }
    }
    rep(i, ans.size()){
        rep(j, ans[i].size()){
            cout << ans[i][j]; 
            if(i==ans.size()-1 && j==ans[i].size()-1) cout << el;
            else cout << " ";
        }
    }
    return 0;
}