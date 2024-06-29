// C - Make a Rectangle
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
    rep(i,n) cin >> a[i];
    map<int, int> mp;
    rep(i,n) mp[a[i]]++;
    ll ans = 0, rect = 1;
    // 4個以上ある棒で面積の最大値を求める
    for(auto p=mp.rbegin(); p!=mp.rend(); ++p){
        if(p->second >= 4){
            ans = max(ans, (ll)p->first*p->first);
            break;
        }
    }
    int cnt = 0;
    // 2個以上ある棒が2つ以上存在するなら面積の最大値を求める
    for(auto p=mp.rbegin(); p!=mp.rend(); ++p){
        if(cnt<2 && p->second>=2){
            rect *= p->first;
            cnt++;
            if(cnt == 2){
                ans = max(ans, rect);
                break;
            }
        }
    }
    cout << ans << el;
    return 0;
}
