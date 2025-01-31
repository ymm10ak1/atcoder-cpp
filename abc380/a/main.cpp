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
    string s; cin >> s;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    rep(i,s.size()){
        if(s[i] == '1') cnt1++;
        if(s[i] == '2') cnt2++;
        if(s[i] == '3') cnt3++;
    }
    if(cnt1==1 && cnt2==2 && cnt3==3) cout << "Yes" << el;
    else cout << "No" <<el;
    return 0;
}
