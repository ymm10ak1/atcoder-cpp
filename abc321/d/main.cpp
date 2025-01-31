#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    sort(all(b));
    vector<ll> s(m+1);
    rep(i,m) s[i+1] = s[i]+b[i];
    ll ans = 0;
    rep(i,n){
        // 副菜の価格を選ぶ個数
        int b_cnt = lower_bound(all(b), p-a[i])-b.begin();
        // p(定価)を選ぶ個数
        int p_cnt = b.size()-b_cnt;
        ans += s[b_cnt]+(ll)a[i]*b_cnt+(ll)p*p_cnt;
    }
    cout << ans << el;
    return 0;
}
