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
    int n;
    string t;
    cin >> n >> t;
    // direction 0:東,1:南,2:西,3:北
    int direction = 0;
    int x = 0, y = 0;
    rep(i,t.size()){
        if(t[i]=='S'){
            if(direction == 0) ++x;
            else if(direction == 1) --y;
            else if(direction == 2) --x;
            else if(direction == 3) ++y;
        }else if(t[i]=='R'){
            direction = (direction+1)%4;
        }
    }
    cout << x << " " << y << el;
    return 0;
}