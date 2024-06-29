// C - 4-adjacent
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
    vector<int> a(n);
    map<int, int> mp;
    rep(i,n){
        cin >> a[i];
        ++mp[a[i]%4];
    }
    bool ok = false;
    if(mp[2]>=1){
        if(mp[0] >= mp[1]+mp[3]) ok = true;
    }else{
        if(mp[0] >= mp[1]+mp[3]) ok = true;
        if(mp[0] == mp[1]+mp[3]-1) ok = true;
    }
    if(ok) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
