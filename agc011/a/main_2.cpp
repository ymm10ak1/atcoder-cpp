// A - Airport Bus
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
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> t(n);
    rep(i,n) cin >> t[i];
    sort(all(t));
    ll v = 0LL+t[0]+k;
    int cnt = 0, ans = 0;
    for(int i=0; i<n;){
        while(i<n && cnt<c && (ll)t[i]<=v){ cnt++; i++; }
        cnt = 0;
        ans++;
        v = t[i]+k;
    }
    cout << ans << el;
    return 0;
}
