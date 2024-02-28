// A56 - String Hash
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
    int n, q;
    string s;
    cin >> n >> q >> s;
    // NOTE: s[a]からb-a文字分取得したs1、s[c]からd-c文字分取得したs2を比較するだけではWA
    rep(i,q){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        string s1 = s.substr(a, b-a);
        string s2 = s.substr(c, d-c);
        if(s1 == s2) cout << "Yes" << el;
        else cout << "No" << el;
    }
    // 解説を見ると、1文字目からi文字目までのハッシュ値を用意して、
    // そこからl文字目からr文字目のハッシュ値を計算して解いている
    return 0;
}