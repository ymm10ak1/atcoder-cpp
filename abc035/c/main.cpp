// C - オセロ
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

int board[200005];

int main(){
    int n, q;
    cin >> n >> q;
    rep(i,q){
        int l, r;
        cin >> l >> r;
        ++board[l-1]; // 反転する区間の始まりに+1
        --board[r]; // 反転する区間の終わりに-1
    }
    rep(i,n) board[i+1] = board[i+1]+board[i];
    // 最終的に偶数ならば黒色、奇数ならば白色
    rep(i,n){
        if(board[i]%2 == 0) cout << 0;
        else cout << 1;
        if(i == n-1) cout << el;
    }
    return 0;
}
