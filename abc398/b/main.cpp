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
    const int n = 7;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(s,(1<<n)){
        int cnt = 0;
        vector<int> b(13);
        rep(i,n) if(s>>i & 1){
            cnt++;
            b[a[i]-1]++;
        }
        if(cnt != 5) continue;
        bool ok = false;
        rep(i,13)rep(j,13){
            if(b[i]==3 && b[j]==2) ok = true;
        }
        if(ok){
            cout << "Yes" << el;
            return 0;
        }
    }
    cout << "No" << el;
    return 0;
}
