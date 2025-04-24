// template {{{
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = (1<<30);
const ll LLINF = (1LL<<60);
// }}}

int main(){
    string x; cin >> x;
    int nx = (x[0]-'0')*100+(x[1]-'0')*10+(x[3]-'0');
    if(nx >= 380) cout << 1 << el;
    else if(nx >= 375) cout << 2 << el;
    else if(nx < 375) cout << 3 << el;
    return 0;
}
