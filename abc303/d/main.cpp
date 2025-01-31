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

void chmin(ll& a, ll b){
    if(a > b) a = b;
}

int main(){
    ll x, y, z;
    string s;
    cin >> x >> y >> z >> s;
    // NOTE: 解説を見たところ、ランレングス圧縮せずにそのままDPすれば解けるらしい
    int n = s.size();
    vector<pair<char,int>> vp;
    for(int i=0; i<n;){
        int j = i+1;
        while(j<n && s[i]==s[j]) j++;
        vp.emplace_back(s[i],j-i);
        i = j;
    }
    int m = vp.size();
    vector<vector<ll>> dp(m,vector<ll>(2,2*LLINF));
    if(vp[0].first == 'a'){
        dp[0][0] = x*vp[0].second;
        dp[0][1] = z+y*vp[0].second;
    }else{
        dp[0][0] = y*vp[0].second;
        dp[0][1] = z+x*vp[0].second;
    }
    repi(i,1,m){
        if(vp[i].first == 'a'){
            chmin(dp[i][0], dp[i-1][0]+x*vp[i].second);
            chmin(dp[i][1], dp[i-1][0]+z+y*vp[i].second);
            chmin(dp[i][1], dp[i-1][1]+y*vp[i].second);
            chmin(dp[i][0], dp[i-1][1]+z+x*vp[i].second);
        }else{
            chmin(dp[i][0], dp[i-1][0]+y*vp[i].second);
            chmin(dp[i][1], dp[i-1][0]+z+x*vp[i].second);
            chmin(dp[i][1], dp[i-1][1]+x*vp[i].second);
            chmin(dp[i][0], dp[i-1][1]+z+y*vp[i].second);
        }
    }
    ll ans = min(dp[m-1][0], dp[m-1][1]);
    cout << ans << el;
    return 0;
}
