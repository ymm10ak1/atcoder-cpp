// B26 - Output Prime Numbers
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

const int NMAX = 1000000;

void eratosthenes(vector<bool>& a){
    for(int i=2; i*i<=NMAX; ++i){
        for(int j=2*i; j<=NMAX; j+=i) a[j] = true;
    }
}

int main(){
    int n; cin >> n;
    vector<bool> a(1000010);
    eratosthenes(a);
    repi(i, 2, n+1){
        if(!a[i]) cout << i << el;
    }
    return 0;
}