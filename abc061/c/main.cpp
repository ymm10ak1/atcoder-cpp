// C - Big Array
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
    int n;
    ll k;
    cin >> n >> k;
    map<int,ll> mp;
    rep(i,n){
        int ai, bi;
        cin >> ai >> bi;
        mp[ai] += bi;
    }
    for(auto p : mp){
        if(p.second >= k){
            cout << p.first << el;
            return 0;
        }
        k -= p.second;
    }
    return 0;
}
