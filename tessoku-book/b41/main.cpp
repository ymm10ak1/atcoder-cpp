// B41 - Reverse of Euclid
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

int main(){
    int x, y;
    cin >> x >> y;
    vector<pair<int, int>> ans;
    while(x > 1 || y > 1){
        ans.push_back({x, y});
        if(x>y) x = x-y;
        else y = y-x;
    }
    reverse(all(ans));
    cout << ans.size() << el;
    rep(i,ans.size()){
        cout << ans[i].first << " " << ans[i].second << el;
    }
    return 0;
}