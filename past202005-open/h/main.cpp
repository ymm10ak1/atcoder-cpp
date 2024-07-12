// H - ハードル走
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = n-1; i >= s; --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int dp[100010];

int main(){
    int n, l;
    cin >> n >> l;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    int t1, t2, t3;
    cin >> t1 >> t2 >> t3;
    int dist[3] = {1, 2, 4};
    vector<bool> hur(l+1,false);
    rep(i,n) hur[x[i]] = true;
    rep(i,l+1) dp[i] = INF;
    dp[0] = 0;
    rep(i,l){
        rep(j,3){
            if(i+dist[j] < l){
                int c = hur[i+dist[j]] ? t3 : 0;
                if(j == 0) dp[i+dist[j]] = min(dp[i+dist[j]], dp[i]+t1+c);
                else if(j == 1) dp[i+dist[j]] = min(dp[i+dist[j]], dp[i]+t1+t2+c);
                else if(j == 2) dp[i+dist[j]] = min(dp[i+dist[j]], dp[i]+t1+3*t2+c);
            }else{
                int diff = l-i;
                if(diff == 1){
                    if(j == 0) dp[l] = min(dp[l], dp[i]+t1);
                    else dp[l] = min(dp[l], dp[i]+t1/2+t2/2);
                }else if(diff == 2){
                    if(j == 1) dp[l] = min(dp[l], dp[i]+t1+t2);
                    else dp[l] = min(dp[l], dp[i]+t1/2+3*t2/2);
                }else if(diff == 3){
                    dp[l] = min(dp[l], dp[i]+t1/2+5*t2/2);
                }else if(diff == 4){
                    dp[l] = min(dp[l], dp[i]+t1+3*t2);
                }
            }
        }
    }
    cout << dp[l] << el;
    return 0;
}