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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int na = a==0?24:a;
    if(a < c){
        cout << "Takahashi" << el;
    }else if(c < a){
        cout << "Aoki" << el;
    }else if(a==c){
        if(b <= d) cout << "Takahashi" << el; 
        else cout << "Aoki" << el;
    } 
    return 0;
}