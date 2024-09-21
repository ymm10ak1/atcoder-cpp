// C - Filling 3x3 array
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
    int h[3],w[3];
    cin >> h[0] >> h[1] >> h[2] >> w[0] >> w[1] >> w[2];
    int ans = 0;
    repi(i,1,30){
        repi(j,1,30){
            repi(k,1,30){
                repi(l,1,30){
                    if(h[0]-i-j<=0 || h[1]-k-l<=0 || w[0]-i-k<=0 || w[1]-j-l<=0) continue;
                    int h3 = w[2]-(h[0]-i-j)-(h[1]-k-l);
                    int w3 = h[2]-(w[0]-i-k)-(w[1]-j-l);
                    if(h3<=0 || w3<=0) continue;
                    if(h3 == w3) ans++;
                }
            }
        }
    }
    cout << ans << el;
    return 0;
}
