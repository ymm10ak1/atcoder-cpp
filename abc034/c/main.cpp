// C - 経路
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

const int MOD = 1000000007;
int dp[2][100005];

// 部分解はdpでできたが満点解がわからなかった
// 鉄則本 B30と同じ
int main(){
    int w, h;
    cin >> w >> h;
    dp[0][0] = 1;
    int ans = 0;
    // dpではO(N^2)のため、1<=w<=10^5,1<=h<=10^5より間に合わない
    // 解説より問題を「上にH-1回、右にW-1回移動する組み合わせの個数」を求める問題に読み替えられる
    // これは(H+W-2)回移動する中から、H-1回移動する方法を求めればいいみたい (H+W-2)!/(H-1)!(W-1)!で求まる
    // (H+W-2)!/(H-1)!(W-1)!をどう実装するか (H-1)!(W-1)!の方はフェルマーの小定理を使って(H-1)!(W-1)!の逆元を求めるみたい
    // 実装としては(H+W-2)!*((H-1)!*(W-1)!)^{M-2}をMで割った余りが答えっぽい(M=1000000007)
    // (H+W-2)!,(H-1)!(W-1)!ともに計算途中にMでMODを取っていく
    rep(i,w){
        int mo = i%2;
        rep(j,h){
            if(i==0) dp[mo][j] = dp[mo][0];
            else if(j==0) dp[mo][j] = dp[mo^1][j];
            else if(i>0 && j>0) dp[mo][j] = (dp[mo^1][j]+dp[mo][j-1])%MOD;
        }
        ans = dp[mo][h-1];
        if(i>0) rep(j,h) dp[mo^1][j] = 0;
    }
    cout << ans << el;
    return 0;
}