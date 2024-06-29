// A - Simple Calculator
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
    int x, y;
    cin >> x >> y;
    int ans = 0;
    if(x>=0 && y>=0){
        int c = y==0 ? 1 : 2;
        if(x <= y) ans = y-x;
        else ans = x-y+c;
    }else if((x<0 && y>=0) || (x>=0 && y<0)){
        int c = y==0 ? 0 : 1;
        if(abs(x) <= abs(y)) ans = abs(y)-abs(x)+1;
        else ans = abs(x)-abs(y)+c;
    }else if(x<0 && y<0){
        if(abs(x) <= abs(y)) ans = abs(y)-abs(x)+2;
        else ans = abs(x)-abs(y);
    }
    cout << ans << el;
    return 0;
}
