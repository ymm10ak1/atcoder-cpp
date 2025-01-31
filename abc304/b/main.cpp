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
    if(n>=1000 && n<10000){
        n = n-(n%10);
    }else if(n>=10000 && n<100000){
        n = n-(n%100);
    }else if(n>=100000 && n<1000000){
        n = n-(n%1000);
    }else if(n>=1000000 && n<10000000){
        n = n-(n%10000);
    }else if(n>=10000000 && n<100000000){
        n = n-(n%100000);
    }else if(n>=100000000 && n<1000000000){
        n = n-(n%1000000);
    }
    cout << n << el;
    return 0;
}
