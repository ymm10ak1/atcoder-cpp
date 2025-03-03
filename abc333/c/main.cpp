#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n; cin >> n;
    vector<ll> r;
    ll x = 1;
    r.push_back(x);
    rep(i,17){
        x = r.back()*10+1;
        r.push_back(x);
    }
    set<ll> st;
    rep(i,r.size()){
        rep(j,r.size()){
            rep(k,r.size()) st.insert(r[i]+r[j]+r[k]); 
        }
    }
    ll ans = 0; int cnt =0;
    for(ll d : st){
        cnt++;
        if(cnt == n) ans = d;
    }
    cout << ans << el;
    return 0;
}
