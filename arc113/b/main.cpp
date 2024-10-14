// B - A^B^C
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
    int a, b, c;
    cin >> a >> b >> c;
    if(a%10==0 || a%10==1 || a%10==5 || a%10==6){
        cout << a%10 << el;
    }else if(a%10==4 || a%10==9){
        int bm[2];
        if(a%10==4) bm[0]=6, bm[1]=4;
        if(a%10==9) bm[0]=1, bm[1]=9;
        cout << bm[b%2] << el;
    }else{
        int ai = a%10, v = 1;
        int am[4];
        rep(i,4){
            v *= ai;
            am[(i+1)%4] = v%10;
        }
        if(c == 1){
            cout << am[b%4] << el;
        }else if(c%2 == 0){
            cout << am[b%2] << el;
        }else if(c%2 == 1){
            int bi = b%4;
            if(bi == 2) bi = 0;
            cout << am[bi] << el;
        }
    }
    return 0;
}
