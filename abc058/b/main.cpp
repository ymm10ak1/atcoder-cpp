// B - ∵∴∵
#include<bits/stdc++.h>
#define repi(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i=n-1; i>=s; --i)
using namespace std;
using ll = long long;

int main(){
    string o, e;
    cin >> o;
    cin >> e;
    int oe_sub = o.size()-e.size();
    rep(i, e.size()){
        cout << o[i];
        cout << e[i];
    }
    if(oe_sub > 0) cout << o[o.size()-1] << endl;
    else cout << endl;
    return 0;
}