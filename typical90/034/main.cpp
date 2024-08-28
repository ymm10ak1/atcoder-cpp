// 034 - There are few types of elements（★4）
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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    // しゃくとり法
    int r = 0, ans = 0;
    map<int, int> mp;
    rep(l,n){
        while(r<n){
            mp[a[r]]++;
            if((int)mp.size() > k){
                mp[a[r]]--;
                break;
            }
            r++;
        }
        ans = max(ans, r-l);
        // a[l]を1個除く
        mp[a[l]]--;
        if(mp[a[l]] <= 0) mp.erase(a[l]);
    }
    cout << ans << el;
    return 0;
}
