// C - Many Medians
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
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    vector<int> b = x;
    sort(all(b));
    map<int, int> mp;
    int m = n/2;
    rep(i,n){
        int l = i;
        if(m <= l) mp[b[i]] = b[m-1];
        else mp[b[i]] = b[i+m-l];
    }
    rep(i,n) cout << mp[x[i]] << el;
    return 0;
}
