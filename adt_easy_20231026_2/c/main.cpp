// C - Go Straight and Turn Right
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

int main(){
    int n;
    string t;
    cin >> n >> t;
    int x = 0, y = 0;
    int r = 0;
    rep(i, t.size()){
        if(t[i] == 'S'){
            if(r == 0) x++;
            else if(r == 1) y--;
            else if(r == 2) x--;
            else if(r == 3) y++;
        }else{
            r = (r+1)%4;
        }
    }
    cout << x << " " << y << el;
    return 0;
}