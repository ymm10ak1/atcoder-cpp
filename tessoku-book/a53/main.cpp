// A53 - Priority Queue
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
    int q; cin >> q;
    priority_queue<int, vector<int>, greater<int>> que;
    rep(i,q){
        int type; cin >> type;
        if(type == 1){
            int x; cin >> x;
            que.push(x);
        }else if(type == 2){
            cout << que.top() << el;
        }else if(type == 3){
            que.pop();
        }
    }
    return 0;
}