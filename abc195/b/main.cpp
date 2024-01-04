// B - Many Oranges
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

// 解けなかったため解説のコードを書いている
int main(){
    int a, b, w;
    cin >> a >> b >> w;
    w *= 1000;
    int min_ans = INF, max_ans = 0;
    bool ok = false;

    // NOTE: 考えてもよく分からなかったため解説をみる。(以下解説)
    // 以下のような判定問題を考える。
    // 問題: 1個がAg以上Bg以下のみかんをちょうどN個選んでWkgにすることはできるか？
    // この問題に対する答えは、AN<=1000W<=BNが成り立つときYes, 成り立たないときNo.
    // (最初AgのみかんをN個選んで、少しずつ大きなみかんと交換することをイメージ)
    // したがって、Nを全探索することで答えを求めることができます。

    repi(i, 1, w+1){
        if(w>=a*i && w<=b*i){
            min_ans = min(min_ans, i);
            max_ans = max(max_ans, i);
        }
    }
    if(max_ans == 0) cout << "UNSATISFIABLE" << el;
    else printf("%d %d\n", min_ans, max_ans);
    return 0;
}