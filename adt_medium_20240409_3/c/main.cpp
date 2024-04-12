// C - Split?
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

// 解説みて実装する(問題文を理解できなかった)
int main(){
    string s; cin >> s;
    if(s[0] == '1'){
        cout << "No" << el;
        return 0;
    }
    // true:列の中で立っているピンが存在する, false:立っているピンが存在しない
    bool pin[7];
    pin[0] = (s[6]=='1');
    pin[1] = (s[3]=='1');
    pin[2] = (s[7]=='1') | (s[1]=='1');
    pin[3] = (s[4]=='1') | (s[0]=='1');
    pin[4] = (s[8]=='1') | (s[2]=='1');
    pin[5] = (s[5]=='1');
    pin[6] = (s[9]=='1');
    repi(i,1,7){
        rep(j,i){
            // 立っているピンが1本以上列同士の間にピンがすべて倒れている列を確認する
            if(pin[i] && pin[j]){
                bool ok = false;
                // 間のピン(j<k<i)を調べる
                repi(k,j+1,i){
                    if(!pin[k]) ok = true;
                }
                if(ok){
                    cout << "Yes" << el;
                    return 0;
                }
            }
        }
    }
    cout << "No" << el;
    return 0;
}