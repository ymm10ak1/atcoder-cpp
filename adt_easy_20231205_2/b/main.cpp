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
    cin >> n;
    vector<pair<int, string>> a(n);
    rep(i, n) cin >> a[i].second >> a[i].first;
    int min_idx = 0, min_age = INF;
    rep(i, n){
        if(a[i].first<min_age){
            min_age = a[i].first;
            min_idx = i;
        }
    }
    repi(i, min_idx, n) cout << a[i].second << el;
    rep(i, min_idx) cout << a[i].second << el;
    return 0;
}