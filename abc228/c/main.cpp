// C - Final Day
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
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    rep(i,n)rep(j,3){
        int pi; cin >> pi;
        p[i] += pi;
    }
    vector<int> np = p;
    sort(rall(np));
    int border = np[k-1];
    rep(i,n){
        if(border <= p[i]+300) cout << "Yes" << el;
        else cout << "No" << el;
    }
    return 0;
}
