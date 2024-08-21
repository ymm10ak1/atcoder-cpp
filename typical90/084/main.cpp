// 084 - There are two types of characters（★3）
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

// NOTE: 解説をみるとランレングス圧縮を使っても解ける
// 区間をoだけのグループ,xだけのグループを数えそれらの選び方の和(等差数列の和)を求めて
// それを区間[l,r]の選び方の数(条件を満たさないものを含む)から引く
int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> maru, batsu;
    rep(i,n){
        if(s[i] == 'o') maru.push_back(i);
        else batsu.push_back(i);
    }
    ll ans = 0;
    rep(i,maru.size()){
        int idx = lower_bound(all(batsu), maru[i])-batsu.begin();
        if(idx == (int)batsu.size()) continue;
        ans += (n-batsu[idx]);
    }
    rep(i,batsu.size()){
        int idx = lower_bound(all(maru), batsu[i])-maru.begin();
        if(idx == (int)maru.size()) continue;
        ans += (n-maru[idx]);
    }
    cout << ans << el;
    return 0;
}
