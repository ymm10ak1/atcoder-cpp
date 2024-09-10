// C - Four Variables
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
    // 1~N-1の約数の個数を求める
    vector<ll> div(n,0);
    repi(i,1,n){
        vector<int> num;
        for(int j=1; j*j<=i; ++j){
            if(i%j != 0) continue;
            num.push_back(j);
            if(i/j != j) num.push_back(i/j);
        }
        div[i] = num.size();
    }
    ll ans = 0;
    repi(i,1,n) ans += div[i]*div[n-i];
    cout << ans << el;
    return 0;
}
