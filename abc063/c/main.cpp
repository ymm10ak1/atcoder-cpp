// C - Bugged
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
    vector<int> s(n);
    int sum = 0;
    rep(i,n){
        cin >> s[i];
        sum += s[i];
    }
    sort(all(s));
    if(sum%10 == 0){
        rep(i,n){
            if(s[i]%10 != 0){
                sum -= s[i];
                break;
            }
        }
    }
    if(sum%10 == 0) cout << 0 << el;
    else cout << sum << el;
    return 0;
}
