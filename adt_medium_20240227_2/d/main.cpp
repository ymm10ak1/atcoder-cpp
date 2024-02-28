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
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> res;
    rep(i,n-1){
        res.push_back(a[i]);
        if(a[i+1]-a[i] > 1) repi(j,a[i]+1,a[i+1]) res.push_back(j);
        else if(a[i]-a[i+1] > 1) rrepi(j,a[i],a[i+1]+1) res.push_back(j);
    }
    res.push_back(a[n-1]);
    rep(i,res.size()){
        printf("%d%c", res[i], i==res.size()-1?'\n':' ');
    }
    return 0;
}