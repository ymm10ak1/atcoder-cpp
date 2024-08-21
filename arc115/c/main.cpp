// N Coloring
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
    vector<int> ans(n+1, 2);
    ans[1] = 1;
    repi(i,2,n+1){
        for(int j=i*2; j<=n; j+=i) ans[j] = max(ans[j], ans[i]+1);
    }
    repi(i,1,n+1) printf("%d%c", ans[i], i==n?'\n':' ');
    return 0;
}
