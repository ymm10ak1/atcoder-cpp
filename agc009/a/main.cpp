// A - Multiple Array 
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
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    rep(i, n) cin >> a[i].first >> a[i].second;
    reverse(all(a));
    ll diff = 0;
    rep(i, n){
        a[i].first += diff;
        if(a[i].first%a[i].second == 0){
            continue;
        }else if(a[i].first > a[i].second){
            diff += (a[i].second-(a[i].first%a[i].second));
        }else if(a[i].first < a[i].second){
            diff += abs(a[i].first-a[i].second);
        }
    }
    cout << diff << el;
    return 0;
}