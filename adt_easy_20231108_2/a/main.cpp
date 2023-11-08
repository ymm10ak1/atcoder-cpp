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
    map<int, int> mpx, mpy;
    int x[3], y[3];
    rep(i, 3){
        cin >> x[i] >> y[i];
        mpx[x[i]]++;
        mpy[y[i]]++;
    }
    int ans_x = 0, ans_y = 0;
    rep(i, 3){
        if(mpx[x[i]] == 1) ans_x = x[i];
        if(mpy[y[i]] == 1) ans_y = y[i];
    }
    cout << ans_x << " " << ans_y << el;
    return 0;
}