// template {{{
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
// }}}

int main(){
    ll n; cin >> n;
    vector<ll> x = {1}, zero = {1};
    ll m = n;
    while(m > 0){
         m -= x.back();
         x.push_back(zero[max((int)zero.size()-2, 0)]*9);
         zero.push_back(zero[max((int)zero.size()-2, 0)]*10);
    }
    int keta = 0;
    rep(i,x.size()){
        if(n <= x[i]){
            keta = i;
            break;
        }
        n -= x[i];
    }
    string ans = "";
    if(keta > 0){
        bool first = true;
        bool check = keta%2?true:false;
        n--;
        while(keta > 0){
            ll p = n/zero[max(keta-2, 0)];
            n -= p*zero[max(keta-2, 0)];
            if(first){
                ans += (p+1)+'0';
                first = false;
            }else{
                ans += p+'0';
            }
            keta -= 2;
        }
        string rans = ans;
        reverse(all(rans));
        if(check) ans.pop_back();
        cout << ans+rans << el;
    }else{
        cout << '0' << el;
    }
    return 0;
}
