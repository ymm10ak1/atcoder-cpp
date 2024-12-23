// C - 列
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
    int n;
    ll k;
    cin >> n >> k;
    vector<int> s(n);
    rep(i,n) cin >> s[i];
    rep(i,n) if(s[i]==0){
        cout << s.size() << el;
        return 0;
    }
    int ans = 0, r = 0;
    ll mul = 1;
    rep(l,n){
        while(r<n && mul*s[r]<=k){
            mul *= s[r];
            r++;
        }
        ans = max(ans, r-l);
        if(l == r) r++;
        else if(s[l] > 0) mul /= s[l];
    }
    cout << ans << el;
    return 0;
}
