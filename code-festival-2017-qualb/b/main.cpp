// B - Problem Set
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
    map<int, int> mp;
    rep(i,n){
        int d; cin >> d;
        mp[d]++;
    }
    int m; cin >> m;
    vector<int> t(m);
    rep(i,m) cin >> t[i];
    rep(i,m){
        if(mp[t[i]] >= 1){
            mp[t[i]]--;
        }else{
            cout << "NO" << el;
            return 0;
        }
    }
    cout << "YES" << el;
    return 0;
}
