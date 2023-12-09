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
    int k;
    cin >> k;
    int h = 21, m = k;
    if(k >= 60){
        ++h;
        m = k-60;
    }
    if(m < 10) cout << h << ":" << 0 << m << el;
    else cout << h << ":" << m << el;
    return 0;
}