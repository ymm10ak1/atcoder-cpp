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
    int a, b;
    cin >> a >> b;
    int ra = a%3, rb = b%3;
    bool ok = false;
    if(ra==1 && rb==2 && b-a==1) ok = true;
    if(ra==2 && rb==0 && b-a==1) ok = true;
    if(ok) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
