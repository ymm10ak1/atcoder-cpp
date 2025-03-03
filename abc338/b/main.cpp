#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    string s; cin >> s;
    vector<int> cnt(26);
    for(char c : s) cnt[c-97]++;
    vector<P> vp;
    rep(i,26) vp.emplace_back(cnt[i],-i);
    sort(rall(vp));
    cout << char(97+(-vp[0].second)) << el;
    return 0;
}
