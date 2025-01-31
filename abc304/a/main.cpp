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
    int n; cin >> n;
    vector<string> s(n);
    vector<int> a(n);
    rep(i,n) cin >> s[i] >> a[i];
    int mini = 0, minv = a[0];
    rep(i,n){
        if(minv > a[i]){
            mini = i;
            minv = a[i];
        }
    }
    rep(i,n) cout << s[(mini+i)%n] << el;
    return 0;
}
