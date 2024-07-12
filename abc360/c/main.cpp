// C - Move It
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
    vector<int> a(n), w(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> w[i];
    vector<int> cnt(n,0);
    map<int,int> mp;
    priority_queue<int, vector<int>, greater<int>> q;
    rep(i,n){
        cnt[a[i]-1]++;
        // 2回以上荷物を積むとき、コストが大きい方を残しそれ以外は空箱に移動させる用にする
        if(mp[a[i]] != 0){
            if(mp[a[i]] < w[i]){
                q.push(mp[a[i]]);
                mp[a[i]] = w[i];
            }else{
                q.push(w[i]);
            }
        }else{
            mp[a[i]] = w[i];
        }
    }
    int zero = 0;
    rep(i,n) if(cnt[i] == 0) zero++;
    int ans = 0;
    if(zero > 0){
        while(zero > 0){
            ans += q.top();
            q.pop();
            zero--;
        }
    }
    cout << ans << el;
    return 0;
}