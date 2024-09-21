// D
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

void check(vector<string>& b, int x, int y, int r, int c){
    int num = b[x][y]-'0';
    rep(i,r){
        rep(j,c){
            if(b[i][j] == '.') continue;
            if(b[i][j]>='1' && b[i][j]<='9') continue;
            if(b[i][j]=='#' && abs(x-i)+abs(y-j) <= num) b[i][j] = '.';
        }
    }
}

int main(){
    int r, c;
    cin >> r >> c;
    vector<string> b(r);
    rep(i,r) cin >> b[i];
    rep(i,r){
        rep(j,c){
            if(b[i][j]>='1' && b[i][j]<='9'){
                check(b,i,j,r,c);
                b[i][j] = '.';
            }
        }
    }
    rep(i,r) cout << b[i] << el;
    return 0;
}
