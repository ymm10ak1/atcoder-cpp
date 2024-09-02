// C Just K
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
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    int ans = 0;
    rep(bit,(1<<n)){
        vector<string> ns;
        // NOTE: ここの処理をfor文を追加しmapで各文字をカウントする方法にすればnsはいらなくなる
        rep(i,n){
            if((bit>>i) & 1) ns.push_back(s[i]);
        }
        map<char,int> mp;
        rep(i,ns.size()) rep(j,ns[i].size()) ++mp[ns[i][j]];
        int cnt = 0;
        for(auto p : mp) if(p.second == k) ++cnt;
        ans = max(ans, cnt);
    }
    cout << ans << el;
    return 0;
}
