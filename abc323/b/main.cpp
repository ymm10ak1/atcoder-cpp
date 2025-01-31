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
    int n; cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<P> ans(n);
    rep(i,n)rep(j,n){
        ans[i].second = -(i+1);
        if(s[i][j] == 'o') ans[i].first++;
    }
    sort(rall(ans));
    rep(i,n) printf("%d%c", -ans[i].second, i==n-1?'\n':' ');
    return 0;
}
