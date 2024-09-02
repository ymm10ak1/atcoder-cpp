// C - Reordeer Cards
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
    int h, w, n;
    cin >> h >> w >> n;
    map<int, vector<int>> mph, mpw;
    vector<int> nh(n+1), nw(n+1);
    rep(i,n){
        int a, b; cin >> a >> b;
        mph[a].push_back(i+1);
        mpw[b].push_back(i+1);
        nh[i+1] = a;
        nw[i+1] = b;
    }
    int d = 1;
    for(auto p : mph){
        rep(i,p.second.size()) nh[p.second[i]] = d;
        d++;
    }
    d = 1;
    for(auto p : mpw){
        rep(i,p.second.size()) nw[p.second[i]] = d;
        d++;
    }
    repi(i,1,n+1) cout << nh[i] << " " << nw[i] << el;
    return 0;
}
