// C -adjacent Swaps
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n+1);
    rep(i,n){
        a[i] = i+1;
        b[i+1] = i;
    }
    rep(i,q){
        int x; cin >> x;
        int idx = b[x];
        if(idx < n-1){
            swap(a[idx], a[idx+1]);
            swap(b[a[idx]], b[a[idx+1]]);
        }else{
            swap(a[idx], a[idx-1]);
            swap(b[a[idx]], b[a[idx-1]]);
        }
    }
    rep(i,n) printf("%d%c", a[i], i==n-1?'\n':' ');
    return 0;
}
