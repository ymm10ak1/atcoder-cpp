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
    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> cr(n);
    rep(i, n) cin >> cr[i].first;
    rep(i, n) cin >> cr[i].second;
    int ans = 0, c_max = 0;
    bool t_exist = false;
    rep(i, n){
        if(cr[i].first == t){
            if(c_max < cr[i].second){
                ans = i+1;
                c_max = cr[i].second;
                if(!t_exist) t_exist = true;
            }
        }
    }
    if(!t_exist){
        int c1 = cr[0].first, c_max = cr[0].second;
        ans = 1;
        repi(i, 1, n){
            if(c1 == cr[i].first){
                if(c_max < cr[i].second){
                    ans = i+1;
                    c_max = cr[i].second;
                }
            }
        }
    }
    cout << ans << el;
    return 0;
}