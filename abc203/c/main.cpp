// C - Friends and Travel costs
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
    vector<pair<ll,int>> a(n); 
    rep(i,n) cin >> a[i].first >> a[i].second; 
    sort(all(a));
    ll now = 0, m = k;
    rep(i,n){
        ll d = a[i].first-now;
        m -= d;
        if(m < 0){
            cout << now+d+m << el;
            return 0;
        }
        m += a[i].second;
        now = a[i].first;
    }
    cout << now+m << el;
    return 0;
}
