// {{{
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;
// }}}

int main(){
    int n = 3;
    int x[n], y[n];
    rep(i,n) cin >> x[i] >> y[i];
    vector<int> dist;
    rep(i,n-1){
        repi(j,i+1,n) dist.push_back((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    }
    rep(i,n){
        int a = dist[i];
        int b = 0;
        rep(j,n) if(i != j) b += dist[j];
        if(a == b){
            cout << "Yes" << el;
            return 0;
        }
    }
    cout << "No" << el;
    return 0;
}
