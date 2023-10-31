// E - Centers
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

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> a(3*n);
    rep(i, 3*n){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a));
    vector<pair<int, int>> res;
    for(int i=1; i<3*n; i+=3){
        res.push_back(make_pair(a[i].second, a[i].first));
    }
    sort(all(res));
    rep(i, res.size()){
        cout << res[i].second;
        if(i == res.size()-1) cout << el;
        else cout << " ";
    }
    return 0;
}