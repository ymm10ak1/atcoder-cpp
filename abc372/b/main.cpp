// B
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

pair<int,int> f(int m){
    int num = 1;
    int cnt = 0;
    while(num <= m){
        num *= 3;
        cnt++;
    }
    num /= 3;
    cnt--;
    return {num, cnt};
}

int main(){
    int m; cin >> m;
    vector<int> ans;
    while(m > 0){
        auto p = f(m);
        m -= p.first;
        ans.push_back(p.second);
    }
    cout << ans.size() << el;
    rep(i,ans.size()) printf("%d%c", ans[i], i==(int)ans.size()-1?'\n':' ');
    return 0;
}
