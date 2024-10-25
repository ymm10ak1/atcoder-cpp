// C - Triangle?
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
    vector<ll> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    set<tuple<int,int,int>> st;
    rep(i,n-2){
        repi(j,i+1,n-1){
            repi(k,j+1,n){
                ll x1 = x[j]-x[i], x2 = x[k]-x[i];
                ll y1 = y[j]-y[i], y2 = y[k]-y[i];
                ll area = abs(x1*y2-x2*y1);
                area = (area+1)/2;
                if(area > 0) st.insert({i+1,j+1,k+1});
            }
        }
    }
    cout << st.size() << el;
    return 0;
}
