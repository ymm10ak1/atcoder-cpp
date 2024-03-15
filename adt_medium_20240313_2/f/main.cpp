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
    int n;
    ll t;
    cin >> n >> t;
    vector<int> a(n);
    vector<ll> b(n+1, 0);
    ll sum = 0;
    rep(i,n){
        cin >> a[i];
        b[i+1] = b[i]+a[i];
    }
    ll r = t%b[n];
    repi(i,1,n+1){
        if(r <= b[i]){
            cout << i << " " << r-b[i-1] << el;
            return 0;
        }
    }
    return 0;
}