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

int main(){
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n);
    rep(i, n){
        int l; cin >> l;
        vector<int> ai(l);
        rep(j, l) cin >> ai[j];
        a[i] = ai;
    }
    rep(i, q){
        int s, t;
        cin >> s >> t;
        s--; t--;
        cout << a[s][t] << el;
    }
    return 0;
}