// A35 - Game 4
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

// NOTE: 解答を見ると動的計画法で実装していた
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> b = a;
    rep(i, n-1){
        vector<int> c;
        rep(j, b.size()-1){
            if(b.size()%2 == 1) c.push_back(min(b[j], b[j+1]));
            else c.push_back(max(b[j], b[j+1]));
        }
        b = c;
    }
    cout << b[0] << el;
    return 0;
}