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
const int INF = 1e9;
const ll LLINF = 1e18;
// }}}

int main(){
    int q; cin >> q;
    vector<int> card;
    rep(i,100) card.push_back(0);
    rep(qi,q){
        int c; cin >> c;
        if(c == 1){
            int x; cin >> x;
            card.push_back(x);
        }else{
            int x = card.back();
            card.pop_back();
            cout << x << el;
        }
    }
    return 0;
}
