// D - Megalomania
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
    int n; cin >> n;
    vector<int> a(n), b(n);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    rep(i,n){
        cin >> a[i] >> b[i];
        q.push({b[i], a[i]});
    }
    int sta = 0;
    bool ok = true;
    while(!q.empty()){
        pair<int,int> p = q.top(); q.pop();
        sta += p.second;
        if(sta > p.first) ok = false;
    }
    if(ok) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
