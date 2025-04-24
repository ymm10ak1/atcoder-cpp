// template {{{
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 2e9;
const ll LLINF = 2e18;
// }}}

int main(){
    int q; cin >> q;
    map<int,int> mp;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int x; cin >> x;
            mp[x]++;
        }else if(t == 2){
            int x; cin >> x;
            mp[x]--;
            if(mp[x] == 0) mp.erase(x);
        }else{
            cout << mp.size() << el;
        }
    }
    return 0;
}
