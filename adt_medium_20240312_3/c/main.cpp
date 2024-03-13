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
    vector<int> s(n);
    rep(i,n) cin >> s[i];
    vector<int> a(n);
    rep(i,n){
        if(i==0) a[i] = s[i];
        else a[i] = s[i]-s[i-1];
    }
    rep(i,n) printf("%d%c",a[i],i==n-1?'\n':' ');
    return 0;
}