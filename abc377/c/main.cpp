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

const int dx[] = {-2,-2,-1,-1,0,1,1,2,2};
const int dy[] = {-1,1,-2,2,0,-2,2,-1,1};

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i,m){
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }
    set<pair<int,int>> st;
    ll ans = 1LL*n*n;
    rep(i,m){
        rep(j,9){
            int nx = a[i]+dx[j], ny = b[i]+dy[j];
            if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
            st.insert({nx,ny});
        }
    }
    ans -= (int)st.size();
    cout << ans << el;
    return 0;
}
