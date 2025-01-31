// 
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
    int a[4];
    rep(i,4) cin >> a[i];
    map<int,int> mp;
    rep(i,4) mp[a[i]]++;
    bool ok = false;
    if((int)mp.size() == 2) ok = true;
    if(ok) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
