// D - Prediction and Restriction
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

int dp[100005];
char ep[100005];

int main(){
    int n, k, r, s, p;
    string t;
    cin >> n >> k >> r >> s >> p >> t;
    map<char,char> win;
    win['r'] = 'p', win['s'] = 'r', win['p'] = 's';
    map<char,int> score;
    score['r'] = r, score['s'] = s, score['p'] = p;
    dp[0] = score[win[t[0]]];
    ep[0] = win[t[0]];
    // これはおそらくdpではなく貪欲法
    // NOTE: dpで解くにはmod Kでグループを分ける必要がある
    repi(i,1,n){
        if(i-k>=0){
            if(win[t[i]] != ep[i-k]){
                dp[i] = dp[i-1]+score[win[t[i]]];
                ep[i] = win[t[i]];
            }else{
                dp[i] = dp[i-1];
            }
        }else{
            dp[i] = dp[i-1]+score[win[t[i]]];
            ep[i] = win[t[i]];
        }
    }
    cout << dp[n-1] << el;
    return 0;
}