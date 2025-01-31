#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n; cin >> n;
    string ans = "1";
    repi(i,1,n+1){
        int v = -1;
        repi(j,1,10){
            if(n%j != 0) continue;
            int nn = n/j;
            if(i%nn == 0){
                v = j;
                break;
            }
        }
        if(v == -1)  ans += '-';
        else ans += v+'0';
    }
    cout << ans << el;
    return 0;
}
