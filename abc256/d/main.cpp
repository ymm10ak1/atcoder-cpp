// D - Union of Interval
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
    vector<pair<int,int>> a(n);
    rep(i,n) cin >> a[i].first >> a[i].second;
    sort(all(a));
    int nowl = a[0].first, nowr = a[0].second;
    vector<pair<int,int>> ans;
    repi(i,1,n){
        if(nowr >= a[i].first){
            nowr = max(nowr, a[i].second);
        }else{
            ans.push_back({nowl, nowr});
            nowl = a[i].first;
            nowr = a[i].second;
        }
    }
    ans.push_back({nowl, nowr});
    for(auto p : ans) cout << p.first << " " << p.second << el;
    return 0;
}
