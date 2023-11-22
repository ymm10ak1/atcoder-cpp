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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> cnt;
    rep(i, n){
        cnt.push_back(a[i]);
        if(cnt.size() > 1){
            rep(j, cnt.size()-1) cnt[j] += a[i];
        }
    }
    int ans = 0;
    rep(i, cnt.size()) if(cnt[i] > 3) ++ans;
    cout << ans << el;
    return 0;
}