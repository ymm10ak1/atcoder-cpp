// B42 - Two Faced Cards
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

// NOTE: 以下のやり方ではWAになり、その後考えても解法が思いつかないため解答を見る
ll sum_arr(vector<int>& a, vector<int>& b, bool plus){
    ll a_sum = 0, b_sum = 0;
    rep(i,a.size()){
        if(plus && a[i]>0){
            a_sum += a[i]; b_sum += b[i];
        }
        if(!plus && a[i]<0){
            a_sum += a[i]; b_sum += b[i];
        }
    }
    return abs(a_sum)+abs(b_sum);
}

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    ll ans = 0;
    // 表の総和を正とする場合
    ans = max(ans, sum_arr(a, b, true));
    // 表の総和を負とする場合
    ans = max(ans, sum_arr(a, b, false));
    // 裏の総和を正とする場合
    ans = max(ans, sum_arr(b, a, true));
    // 裏の総和を負とする場合
    ans = max(ans, sum_arr(b, a, false));
    cout << ans << el;
    return 0;
}