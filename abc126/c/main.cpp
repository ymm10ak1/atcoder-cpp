// C - Dice and Coin
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

int po[31];

void pow2(){
    int res = 1;
    po[0] = res;
    rep(i,30){
        res *= 2;
        po[i+1] = res;
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    pow2();
    int bunshi = 0, bunbo = 1;
    repi(i,1,n+1){
        if(i < k){
            int v = i, cnt = 0;
            while(v < k){
                v *= 2; ++cnt;
            }
            if(i == 1){
                bunbo = po[cnt];
                bunshi = 1;
            }else{
                bunshi += bunbo/po[cnt];
            }
        }else{
            bunshi += bunbo;
        }
    }
    double ans = (double)bunshi/n/bunbo;
    printf("%.12f\n", ans);
    return 0;
}
