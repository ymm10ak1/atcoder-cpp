// 010 - Score Sum Queries(★2)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repi(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i=n-1; i>=s; --i)
#define repli(i, s, n) for(ll i=(s); i<(ll)(n); ++i)
#define repl(i, n) repli(i, 0LL, n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LINF = 1e18;

int main(){
    int n;
    cin >> n;
    vector<int> c(n), p(n);
    vector<int> a(n, 0), b(n, 0);
    rep(i, n){
        cin >> c[i] >> p[i];
        if(c[i] == 1) a[i] = p[i];
        else b[i] = p[i];
    } 
    vector<int> a_cs(n+1, 0), b_cs(n+1, 0);
    rep(i, n){
        a_cs[i+1] = a_cs[i]+a[i];
        b_cs[i+1] = b_cs[i]+b[i];
    }
    int q;
    cin >> q;
    rep(i, q){
        int l, r;
        cin >> l >> r;
        cout << a_cs[r]-a_cs[l-1] << " " << b_cs[r]-b_cs[l-1] << el;
    }
    return 0;
}