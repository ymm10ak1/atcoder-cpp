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

int main(){
    string s; cin >> s;
    int n = s.size();
    vector<int> cs(26);
    bool two = false;
    for(char c : s){
        cs[c-97]++;
        if(cs[c-97] > 1) two = true;
    }
    ll ans = two ? 1 : 0;
    rep(i,n){
        int j = s[i]-97;
        if(cs[j] > 0) cs[j]--;
        int cnt = n-i-1-cs[j];
        ans += cnt;
    }
    cout << ans << el;
    return 0;
}
