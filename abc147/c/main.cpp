// C - HonestOrUnkind2
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repi(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i=n-1; i>=s; --i)
#define repli(i, s, n) for(ll i=(s); i<(ll)(n); ++i)
#define repl(i, n) repli(i, 0LL, n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LINF = 1e18;

bool check(const vector<vector<pair<int, int>>> &a, const vector<int> &hu, const int n){
    rep(i, n){
        if(!hu[i]) continue;
        rep(j, a[i].size()){
            int x = a[i][j].first;
            int y = a[i][j].second;
            if(hu[x] != y) return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> a(n);
    rep(i, n){
        int ai; cin >> ai;
        vector<pair<int, int>> vp;
        rep(j, ai){
            pair<int, int> p; cin >> p.first >> p.second;
            p.first--;
            vp.push_back(p);
        }
        a[i] = vp;
    }
    int ans = 0;
    rep(bit, (1<<n)){
        int shojiki = 0;
        vector<int> hu(n);
        rep(i, n){
            if(bit&(1<<i)){
                shojiki++;
                hu[i] = 1;
            }else{
                hu[i] = 0;
            }
        }
        if(check(a, hu, n)) ans = max(ans, shojiki);
    }
    cout << ans << el;
    return 0;
}