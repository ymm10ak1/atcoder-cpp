// C - Reorder Cards
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

vector<int> compression(vector<int> a){
    int n = a.size();
    map<int,int> mp;
    rep(i,n) mp[a[i]] = 0;
    int d = 1;
    for(auto& p : mp) p.second = d++;
    rep(i,n) a[i] = mp[a[i]];
    return a;
}

int main(){
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    a = compression(a);
    b = compression(b);
    rep(i,n) cout << a[i] << " " << b[i] << el;
    return 0;
}
