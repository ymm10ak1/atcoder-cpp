// D - Divide by 2 or 3
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

int solve(vector<int>& a, int n){
    int g = a[0];
    repi(i,1,n) g = gcd(g, a[i]);
    int ret = 0;
    rep(i,n){
        int cnt = 0;
        if(a[i]!=g && a[i]%2!=0 && a[i]%3!=0) return -1;
        a[i] /= g;
        while(a[i]%2 == 0){
            a[i] /= 2;
            cnt++;
        }
        while(a[i]%3 == 0){
            a[i] /= 3;
            cnt++;
        }
        if(a[i] > 1) return -1;
        ret += cnt;
    }
    return ret;
}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    cout << solve(a, n) << el;
    return 0;
}
