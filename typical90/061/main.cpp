// 061 - Deck（★2）
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
    int q; cin >> q;
    deque<int> deq;
    rep(i,q){
        int t, x; cin >> t >> x;
        if(t == 1) deq.push_front(x);
        else if(t == 2) deq.push_back(x);
        else if(t == 3) printf("%d\n", deq[x-1]);
    }
    return 0;
}
