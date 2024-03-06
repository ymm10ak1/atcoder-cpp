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

// 難しくて解けなかった
// 解説より靴下の個数が偶数の場合は、(a[0],a[1]),(a[2],a[3])...,(a[n-2],a[n-1]のようにA)の隣接するペアでの差を足せば良い
// 奇数の場合は1つ余らせるAの値を選んで(このときの値は奇数番目の値)偶数個にして,隣接するペアの差を足していく
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    int cnt = 0;
    rep(i,k){
        cin >> a[i];
    }
    int nn = (2*n-k)/2;
    if(n-k >= nn){
        cout << 0 << el;
        return 0;
    }
    nn -= n-k;
    int ans = 0;
    vector<int> b;
    vector<bool> check(k);
    repi(i,1,k-1){
        if(abs(a[i]-a[i+1])<abs(a[i]-a[i-1])){
            ans += a[i]-a[i+1];
            check[i]; check[i+1];
        }
    }
    cout << ans << el;
    return 0;
}