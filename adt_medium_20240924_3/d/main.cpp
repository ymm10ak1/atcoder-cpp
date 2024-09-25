// D
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
    vector<int> d(n);
    rep(i,n) cin >> d[i];
    int ans = 0;
    rep(i,n){
        rep(j,d[i]){
            bool ng = false;
            int ni = i+1;
            int nj = j+1;
            int da = ni%10;
            while(ni > 0){
                if(da != ni%10){
                    ng = true;
                    break;
                }
                ni /= 10;
            }
            if(ng) continue;
            while(nj > 0){
                if(da != nj%10){
                    ng = true;
                    break;
                }
                nj /= 10;
            }
            if(ng) continue;
            ++ans;
        }
    }
    cout << ans << el;
    return 0;
}
