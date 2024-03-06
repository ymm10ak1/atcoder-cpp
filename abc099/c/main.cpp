// C - Strange Bank
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

int main(){
    int n; cin >> n;
    const int SIZE = 1e5;
    vector<int> mo = {1};
    int six = 6, nine = 9;
    while(six<=SIZE){
        mo.push_back(six); six *= 6;
    }
    while(nine<=SIZE){
        mo.push_back(nine); nine *= 9;
    }
    vector<int> dp(n+1, INF);
    dp[0] = 0;
    // 前計算せず、このfor分の中で6の乗数、9の乗数をnを超えない範囲で計算しながらdpを行う方法もあり
    repi(i,1,n+1){
        rep(j,mo.size()){
            if(i-mo[j] >= 0) dp[i] = min(dp[i], dp[i-mo[j]]+1);
        }
    }
    cout << dp[n] << el;
    return 0;
}