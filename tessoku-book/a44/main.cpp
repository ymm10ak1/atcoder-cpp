// A44 - Change and Reverse
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i,n) a[i] = i+1;
    bool rev = false;
    rep(i,q){
        int j,x,y;
        cin >> j;
        if(j == 1){
            cin >> x >> y;
            if(rev) a[n-x] = y;
            else a[x-1] = y;
        }else if(j == 2){
            rev = !rev;
        }else if(j == 3){
            cin >> x;
            if(rev) cout << a[n-x] << el;
            else cout << a[x-1] << el;
        }
    }
    return 0;
}