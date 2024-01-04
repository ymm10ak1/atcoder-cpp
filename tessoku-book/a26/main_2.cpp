// Prime Check
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

void eratosthenes(vector<bool>& a, int n){
    for(int i=2; i*i<=n; ++i){
        for(int j=i; j*i<=n; ++j) a[i*j] = true;
    }
}

int main(){
    int q; cin >> q;
    vector<bool> a(300010, false);
    eratosthenes(a, 300010);
    rep(i, q){
        int x; cin >> x;
        if(!a[x]) cout << "Yes" << el;
        else cout << "No" << el;
    }
    return 0;
}