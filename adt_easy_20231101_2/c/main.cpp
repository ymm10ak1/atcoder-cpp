// C - KEYENCE building
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
    vector<int> s(n);
    rep(i, n) cin >> s[i];
    map<int, int> mp;
    rep(i, n) mp[s[i]]++;
    int cnt = 0;
    vector<bool> check(1001, false);
    repi(i, 1, 201){
        repi(j, i, 201){
            int a = 4*i*j+3*i+3*j;
            if(!check[a] && mp[a] > 0){
                check[a] = true;
                cnt += mp[a];
            }
        }
    }
    cout << n-cnt << el;
    return 0;
}