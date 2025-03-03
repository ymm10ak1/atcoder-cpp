#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    ll nx = 0, ny = 0, dx = abs(sx-tx), dy = abs(sy-ty);
    ll ans = 0;
    if(dx > dy){
        ny = ty;
        ans += dy;
        if(sx < tx) nx = sx+dy;
        else nx = sx-dy;
        if(nx > tx) swap(nx, tx);
        if(ty%2){
            if(nx%2 == tx%2) ans += (tx-nx)/2;
            else if(tx%2==0 && nx%2==1) ans += (tx-nx)/2;
            else if(tx%2==1 && nx%2==0) ans += (tx-nx+1)/2;
        }else{
            if(nx%2 == tx%2) ans += (tx-nx)/2;
            else if(tx%2==1 && nx%2==0) ans += (tx-nx)/2;
            else if(tx%2==0 && nx%2==1) ans += (tx-nx+1)/2;
        }
    }else{
        nx = tx;
        ans += dx;
        if(sy < ty) ny = sy+dx;
        else ny = sy-dx;
        ans += abs(ty-ny);
    }
    cout << ans << el;
    return 0;
}
