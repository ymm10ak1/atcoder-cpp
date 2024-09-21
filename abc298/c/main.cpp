// C - Cards Query Problem
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
    int n, Q;
    cin >> n >> Q;
    map<int,multiset<int>> box;
    map<int,set<int>> card;
    rep(q,Q){
        int t, i, j;
        cin >> t >> i;
        if(t == 1){
            cin >> j;
            box[j].insert(i);
            card[i].insert(j);
        }else if(t == 2){
            for(int s : box[i]) cout << s << " ";
            cout << el;
        }else{
            for(int s : card[i]) cout << s << " ";
            cout << el;
        }
    }
    return 0;
}
