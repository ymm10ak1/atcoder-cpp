// C - Atcoder Magics
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
    vector<int> a(n), c(n);
    rep(i,n) cin >> a[i] >> c[i];
    vector<pair<int,int>> ap;
    rep(i,n) ap.push_back({a[i], i});
    sort(all(ap));
    priority_queue<pair<int,int>> q;
    rep(i,ap.size()){
        int idx = ap[i].second;
        while(!q.empty()){
            if(c[idx] < q.top().first) q.pop();
            else break;
        }
        q.push({c[idx],idx});
    }
    vector<int> ans;
    while(!q.empty()){
        int idx = q.top().second; q.pop();
        ans.push_back(idx+1);
    }
    sort(all(ans));
    cout << ans.size() << el;
    rep(i,ans.size()) printf("%d%c", ans[i], i==(int)ans.size()-1?'\n':' ');
    return 0;
}
