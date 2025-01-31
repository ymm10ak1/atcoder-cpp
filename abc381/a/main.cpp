// 
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
    int n;
    string s;
    cin >> n >> s;
    bool ok = true;
    if(n%2 == 0) ok = false;
    int cnt1 = 0, cnt2 = 0;
    int idx = 0;
    rep(i,n){
        if(s[i] == '/'){
            idx = i;
            break;
        }
        if(s[i] == '1') cnt1++;
        if(s[i] == '2') ok = false;
    }
    repi(i,idx+1,n){
        if(s[i] == '2') cnt2++;
        if(s[i] == '1') ok = false;
    }
    if(cnt1 != cnt2) ok = false;
    if(ok) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
