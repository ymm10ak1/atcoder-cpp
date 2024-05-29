// C - Takahashi's Information
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

int c[3][3];

int main(){
    rep(i,3) rep(j,3) cin >> c[i][j];
    int a = 0, b = 0;
    bool ok = true;
    // 横方向の増減量が一致するか調べる
    rep(i,3){
        if(i == 0){
            a = c[i][1]-c[i][0];
            b = c[i][2]-c[i][1];
        }else{
            if(a!=c[i][1]-c[i][0] || b!=c[i][2]-c[i][1]) ok = false;
        }
    }
    // 縦方向の増減量が一致するか調べる
    rep(i,3){
        if(i == 0){
            a = c[1][i]-c[0][i];
            b = c[2][i]-c[1][i];
        }else{
            if(a!=c[1][i]-c[0][i] || b!=c[2][i]-c[1][i]) ok = false;
        }
    }
    if(ok) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
