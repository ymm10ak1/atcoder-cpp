// D
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
    repi(i,n,1000){
        int num = i;
        int d[3];
        rep(i,3){
            d[i] = num%10;
            num /= 10;
        }
        if(d[1]*d[2] == d[0]){
            cout << i << el;
            return 0;
        }
    }
    return 0;
}
