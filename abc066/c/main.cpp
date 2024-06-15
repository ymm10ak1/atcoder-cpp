// C - pushpush
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
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    deque<int> deq;
    deq.push_back(a[0]);
    bool backp = true;
    repi(i,1,n){
        if(backp) deq.push_back(a[i]);
        else deq.push_front(a[i]);
        backp = !backp;
    }
    if(backp) rep(i,deq.size()) printf("%d%c", deq[i], i==(int)deq.size()-1?'\n':' ');
    else rrepi(i,deq.size(),0) printf("%d%c", deq[i], i==0?'\n':' ');
    return 0;
}
