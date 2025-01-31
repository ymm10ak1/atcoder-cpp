// 
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

// NOTE: ABCDEの部分列の列挙はbit全探索でいける
int main(){
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    vector<string> s = {
        "ABCDE",
        "BCDE",
        "ACDE",
        "ABDE",
        "ABCE",
        "ABCD",
        "CDE",
        "BDE",
        "ADE",
        "BCE",
        "ACE",
        "BCD",
        "ABE",
        "ACD",
        "ABD",
        "ABC",
        "DE",
        "CE",
        "BE",
        "CD",
        "AE",
        "BD",
        "AD",
        "BC",
        "AC",
        "AB",
        "E",
        "D",
        "C",
        "B",
        "A",
    };
    vector<pair<int,string>> ans;
    rep(i,s.size()){
        int sum = 0;
        rep(j,s[i].size()){
            if(s[i][j] == 'A') sum += a;
            if(s[i][j] == 'B') sum += b;
            if(s[i][j] == 'C') sum += c;
            if(s[i][j] == 'D') sum += d;
            if(s[i][j] == 'E') sum += e;
        }
        ans.emplace_back(-sum,s[i]);
    }
    sort(all(ans));
    rep(i,ans.size()) cout << ans[i].second << el;
    return 0;
}
