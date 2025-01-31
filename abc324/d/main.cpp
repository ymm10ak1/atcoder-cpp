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
    int n;
    string s;
    cin >> n >> s;
    ll x = 1;
    rep(i,n) x *= 10;
    vector<ll> p;
    for(ll i=0; i*i<=x; ++i) p.push_back(i*i);
    vector<int> cnt(10);
    rep(i,n) cnt[s[i]-'0']++;
    int ans = 0;
    rep(i,p.size()){
        vector<int> v = cnt;
        bool ok = true;
        rep(j,n){
            int d = p[i]%10; p[i] /= 10;
            if(v[d] > 0) v[d]--;
            else{
                ok = false;
                break;
            }
        }
        if(ok) ans++;
    }
    cout << ans << el;
    return 0;
}
