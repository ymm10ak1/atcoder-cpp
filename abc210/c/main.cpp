// C - Colorful Candies
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
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    rep(i,n) cin >> c[i];
    map<int,int> mp;
    rep(i,k) mp[c[i]]++;
    int ans = mp.size();
    repi(i,k,n){
        mp[c[i-k]]--;
        if(mp[c[i-k]] == 0) mp.erase(c[i-k]);
        mp[c[i]]++;
        ans = max(ans, (int)mp.size());
        
    }
    cout << ans << el;
    return 0;
}
