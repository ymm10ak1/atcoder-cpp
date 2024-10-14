// C - 321-like Searcher
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

int dp[10][10];
vector<string> ss;

void f(string s, int num, int di, const int maxDigit){
    s += num+'0';
    if(di == maxDigit){
        ss.push_back(s);
        s.pop_back();
        return;
    }
    rrepi(i,num,0) f(s, i, di+1, maxDigit);
    return;
}

// NOTE: 0~9の各数字について選ぶか選ばないかなので、2^10通りを試せばいい(bit全探索)
// ただし、何も選ばないのと0だけ選ばれているのは除く必要がある
// for文で9~0で回し、それぞれ使うかを集合を2進数としたときのi桁目が1かどうかで確認する
int main(){
    int k; cin >> k;
    dp[0][0] = 1;
    rep(i,10){
        rep(j,10){
            if(i == 0){
                dp[i][j] = 1;
            }else if(i>0 && j>0){
                dp[i][j] = dp[i-1][j-1]+dp[i][j-1];
            }
        }
    }
    rep(i,10)rep(j,10){
        if(i==0 && j==0) continue;
        k -= dp[i][j];
        if(k <= 0){
            f("",j,1,i+1);
            sort(all(ss));
            k += dp[i][j];
            cout << ss[k-1] << el;
            return 0;
        }
    }
    return 0;
}
