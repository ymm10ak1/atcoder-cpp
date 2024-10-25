// C
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

const int dx[] = {-1,-1,-1,0,0,1,1,1};
const int dy[] = {-1,0,1,-1,1,-1,0,1};

int main(){
    int n; cin >> n;
    vector<string> a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    rep(i,n){
        rep(j,n){
            rep(k,8){
                ll num = 0;
                int ni = i, nj = j;
                rep(l,n){
                    num = (num*10)+(a[ni][nj]-'0');
                    ni = (ni+dx[k])%n, nj = (nj+dy[k])%n;
                    if(ni < 0) ni += n;
                    if(nj < 0) nj += n;
                }
                ans = max(ans,num);
            }
        }
    }
    cout << ans << el;
    return 0;
}
