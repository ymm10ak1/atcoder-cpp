// C - Loong Tracking
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
    deque<pair<int,int>> de;
    rep(i,n) de.emplace_back(i+1,0);
    rep(i,q){
        int t; cin >> t;
        if(t == 1){
            char c; cin >> c;
            pair<int,int> p = de.front();
            if(c == 'R') p.first++;
            else if(c == 'L') p.first--;
            else if(c == 'U') p.second++;
            else if(c == 'D') p.second--;
            de.emplace_front(p);
            de.pop_back();
        }else{
            int p; cin >> p;
            cout << de[p-1].first << " " << de[p-1].second << el;
        }
    }
    return 0;
}
