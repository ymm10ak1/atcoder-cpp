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
    int x, y, z;
    cin >> x >> y >> z;
    if((x<0&&y>0) || (x>0&&y<0)){
        cout << abs(x) << el;
        return 0;
    }
    if(x<0 && y<0){ x *= -1; y*= -1; z *= -1; }
    int ans = 0;
    if(x > y){
        if(z>=x || (y<=z&&z<=x)){
            cout << -1 << el;
            return 0;
        }
        if(0<=z && z<=y) ans = abs(x);
        else ans = 2*abs(z)+abs(x);
    }else{
        ans = x;
    }
    cout << ans << el;
    return 0;
}