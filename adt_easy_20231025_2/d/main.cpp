// D - Call the ID Number
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repi(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i=n-1; i>=s; --i)
#define repli(i, s, n) for(ll i=(s); i<(ll)(n); ++i)
#define repl(i, n) repli(i, 0LL, n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LINF = 1e18;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<bool> cnt(n+1, false);
    rep(i, n){
        if(!cnt[i+1]) cnt[a[i]] = true;
    }
    vector<int> k;
    repi(i, 1, n+1){
        if(!cnt[i]) k.push_back(i);
    }
    sort(all(k));
    cout << k.size() << el;
    rep(i, k.size()){
        cout << k[i];
        if(i == k.size()-1) cout << el;
        else cout << " ";
    }
    return 0;
}