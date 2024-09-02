// B - 高橋くんと文字列操作
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

int main(){
    string s, t;
    cin >> s >> t;
    int n = s.size();
    deque<char> dq;
    rep(i,n) dq.push_back(s[i]);
    if(s == t){
        cout << 0 << el;
        return 0;
    }
    rep(i,n){
        char c = dq.back(); dq.pop_back();
        dq.push_front(c);
        string ss = "";
        rep(j,n) ss += dq[j];
        if(ss == t){
            cout << i+1 << el;
            return 0;
        }
    }
    cout << -1 << el;
    return 0;
}
