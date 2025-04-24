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
    int n, q;
    cin >> n >> q;
    const int M = 200001;
    vector<multiset<int>> box(M);
    vector<set<int>> card(M);
    rep(qi,q){
        int t; cin >> t;
        if(t == 1){
            int i, j; cin >> i >> j;
            card[i].insert(j);
            box[j].insert(i);
        }else if(t == 2){
            int i; cin >> i;
            for(int x : box[i]) cout << x << " ";
            cout << el;
        }else{
            int i; cin >> i;
            for(int x : card[i]) cout << x << " ";
            cout << el;
        }
    }
    return 0;
}
