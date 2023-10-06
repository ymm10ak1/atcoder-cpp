// C - Not so Deverse
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repi(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i=n-1; i>=s; --i)
#define repli(i, s, n) for(ll i=(s); i<(ll)(n); ++i)
#define repl(i, n) repli(i, 0LL, n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LINF = 1e18;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> cnt(200010, 0);
    rep(i, n){
        cin >> a[i];
        cnt[a[i]]++;
    }
    int balls = 0;
    rep(i, cnt.size()) if(cnt[i] != 0) ++balls;
    int diff = balls-k;
    sort(all(cnt));
    int ans = 0;
    rep(i, cnt.size()){
        if(cnt[i] == 0) continue;
        if(diff <= 0) break;
        ans += cnt[i];
        diff--;
    }
    printf("%d\n", ans);
    return 0;
}