// E
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
    string s; cin >> s;
    vector<int> w(n);
    rep(i,n) cin >> w[i];
    vector<int> a,b;
    rep(i,n){
        if(s[i] == '1') a.push_back(w[i]);
        else b.push_back(w[i]);
    }
    if((int)a.size() == 0 || (int)b.size() == 0){
        cout << n << el;
        return 0;
    }
    sort(all(a));
    sort(rall(b));
    int ans = 0;
    rep(i,b.size()){
        int idx = upper_bound(all(a), b[i])-a.begin();
        int bn = (int)b.size()-i;
        ans = max(ans, (int)a.size()-idx+bn);
    }
    sort(all(b));
    rep(i,a.size()){
        int idx = lower_bound(all(b), a[i])-b.begin();
        int an = (int)a.size()-i;
        ans = max(ans, idx+an);
    }
    cout << ans << el;
    return 0;
}
