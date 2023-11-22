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
    cin >> n;
    int aoki;
    vector<bool> c(2*n+1, false);
    while(1){
        rep(i, 2*n+1){
            if(c[i] == false){
                printf("%d\n", i+1);
                fflush(stdout);
                c[i] = true;
                break;
            }
        }
        cin >> aoki;
        if(aoki == 0) break;
        c[aoki-1] = true;
    }
    return 0;
}