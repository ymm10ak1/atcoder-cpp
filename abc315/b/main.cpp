#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int m; cin >> m;
    vector<int> d(m);
    rep(i,m) cin >> d[i];
    int sum = 0;
    rep(i,m) sum += d[i];
    int mid = (sum+1)/2;
    rep(i,m){
        if(mid <= d[i]){
            cout << i+1 << " " << mid << el;;
            return 0;
        }
        mid -= d[i];
    }
    return 0;
}
