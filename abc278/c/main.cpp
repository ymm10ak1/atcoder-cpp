// C - FF
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
    int n, q;
    cin >> n >> q;
    // NOTE: map使わずにset<pair<int,int>>を使ってフォロワーを管理する方法でよかった
    map<int,set<int>> mp;
    rep(i,q){
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1){
            mp[a].insert(b);
        }else if(t == 2){
            if(mp[a].count(b)) mp[a].erase(b);
        }else{
            if(mp[a].count(b) && mp[b].count(a)) cout << "Yes" << el;
            else cout << "No" << el;
        }
    }
    return 0;
}
