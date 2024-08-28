// C - Leftover Recipes
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

// NOTE: 解説見るとAをx個(0<=x<=10^6)作るときに、Bが何個作れるかを求めて(yとする)x+yの最大値が答え
// 片方固定してfor文を回す
int main(){
    int n; cin >> n;
    vector<int> q(n), a(n), b(n);
    rep(i,n) cin >> q[i];
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    int cnt = 0;
    while(true){
        int mina = INF, minb = INF;
        rep(i,n){
            if(a[i] != 0) mina = min(mina, q[i]/a[i]);
            if(b[i] != 0) minb = min(minb, q[i]/b[i]);
        }
        if(mina==0 && minb==0) break;
        if(mina < minb){
            rep(i,n) q[i] -= b[i];
        }else{
            rep(i,n) q[i] -= a[i];
        }
        ++cnt;
    }
    cout << cnt << el;
    return 0;
}
