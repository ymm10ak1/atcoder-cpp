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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];
    rep(i, h-1){
        repi(i2, i+1, h){
            rep(j, w-1){
                repi(j2, j+1, w){
                    int aij1 = a[i][j]+a[i2][j2];
                    int aij2 = a[i2][j]+a[i][j2];
                    if(aij1 > aij2){
                        cout << "No" << el;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "Yes" << el;
    return 0;
}