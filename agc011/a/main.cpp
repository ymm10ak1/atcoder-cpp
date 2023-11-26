// A - Airport Bus 
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
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> t(n);
    rep(i, n) cin >> t[i];
    sort(all(t));
    int ans = 0;
    rep(i, n){
        int cnt = 1;
        int ts = t[i];
        while(i+1<n && cnt<c && ts+k >= t[i+1]){
            ++cnt; ++i;
        }
        ++ans;
    }
    cout << ans << el;
    return 0;
}