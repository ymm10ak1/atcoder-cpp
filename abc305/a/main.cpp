// 
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
    int n; cin >> n;
    int n1 = 0, n2 = 0;
    repi(i,n,101){
        if(i%5 == 0){
            n1 = i;
            break;
        }
    }
    rrepi(i,n+1,0){
        if(i%5 == 0){
                n2 = i;
                break;
        }
    }
    if(abs(n-n1) < abs(n-n2)) cout << n1 << el;
    else cout << n2 << el;
    return 0;
}
