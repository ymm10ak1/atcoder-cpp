// C - Sentou
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
    int n, T;
    cin >> n >> T;
    vector<int> t(n);
    rep(i,n) cin >> t[i];
    ll ans = 0, nxt = T, v = 0;
    repi(i,1,n){
        // 次のスイッチを押す時間の前にお湯が切れる場合、今までのお湯が出た時間を足して次のスイッチを押す時間を起点として時間を測るようにする
        if(nxt < t[i]){
            ans += (nxt-v);
            v = t[i];
        }
        nxt = t[i]+T;
    }
    ans += (nxt-v);
    cout << ans << el;
    return 0;
}
