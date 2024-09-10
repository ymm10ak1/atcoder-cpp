// C - IPFL
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
    string s;
    cin >> n >> s >> q;
    bool flag = true;
    int sta = 0;
    rep(i,q){
        int t, a, b;
        cin >> t >> a >> b;
        --a; --b;
        sta = flag ? 0 : n;
        if(t == 1) swap(s[(sta+a)%(2*n)], s[(sta+b)%(2*n)]);
        else flag = !flag;
    }
    if(!flag){
        string s1 = s.substr(0,n);
        string s2 = s.substr(n,n);
        s = s2+s1;
    }
    cout << s << el;
    return 0;
}
