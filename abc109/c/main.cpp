// C - Skip
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

int gcd(int x, int y){
    if(y == 0) return x;
    else return gcd(y, x%y);
}

int main(){
    int n, X;
    cin >> n >> X;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    x.push_back(X);
    sort(all(x));
    vector<int> diff;
    rep(i,n) diff.push_back(x[i+1]-x[i]);
    sort(all(diff));
    int ans = diff[0];
    repi(i,1,diff.size()){
        ans = gcd(diff[i], ans);
    }
    cout << ans << el;
    return 0;
}
