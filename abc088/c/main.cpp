// C - Takahashi's Infomation
// 嘘解法の可能性あり、a,bが0より大きいことは確定していない
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

bool check(const vector<vector<int>> &c,int b1, int b2, int b3){
    rep(i, c.size()){
        int a1 = c[i][0]-b1;
        int a2 = c[i][1]-b2;
        int a3 = c[i][2]-b3;
        if(a1<0 || a2<0 || a3<0 || a1!=a2 || a2!=a3 || a3!=a1){
            return false;
        }
    }
    return true;
}

int main(){
    vector<vector<int>> c(3, vector<int>(3));
    rep(i, 3) rep(j, 3) cin >> c[i][j];
    rep(i, 101){
        rep(j, 101){
            rep(k, 101){
                if(check(c, i, j, k)){
                    cout << "Yes" << el;
                    return 0;
                }
            }
        }
    }
    cout << "No" << el;
    return 0;
}