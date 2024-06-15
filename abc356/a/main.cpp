// A - Subsegment Reverse
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
    int n, l, r;
    cin >> n >> l >> r;
    int rr = r;
    repi(i,1,n+1){
        if(i>=l && i<=r){
            cout << rr;
            --rr;
        }else{
            cout << i;
        }
        if(i == n) cout << el;
        else cout << " ";
    }
    return 0;
}
