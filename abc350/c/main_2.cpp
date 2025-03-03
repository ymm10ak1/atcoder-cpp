#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    map<int,int> mp;
    rep(i,n) mp[a[i]] = i;
    vector<P> ans;
    rep(i,n){
        if(a[i] == i+1) continue;
        int j = mp[i+1];
        ans.emplace_back(i+1, j+1);
        mp[a[i]] = j;
        mp[i+1] = i;
        swap(a[i], a[j]);
    }
    cout << ans.size() << el;
    for(auto [f,s] : ans) printf("%d %d\n", f, s);
    return 0;
}
