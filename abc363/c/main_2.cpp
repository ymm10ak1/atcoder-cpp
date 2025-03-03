// template {{{
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;
// }}}

int main(){
    int n, k;
    string s;
    cin >> n >> k >> s;
    sort(all(s));
    int ans = 0;
    do{
        bool ok = true;
        rep(i,n-k+1){
            bool pal = true;
            rep(j,k/2) if(s[i+j] != s[i+k-1-j]) pal = false;
            if(pal) ok = false;
        }
        if(ok) ans++;
    }while(next_permutation(all(s)));
    cout << ans << el;
    return 0;
}
