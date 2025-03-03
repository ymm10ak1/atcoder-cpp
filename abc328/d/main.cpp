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
    vector<string> sta;
    int n = s.size(), i = 0;
    while(i < n){
        if(sta.size() > 0){
            if(sta.back().back()=='A' && s[i]=='B'){
                sta.back().push_back(s[i]);
            }else if(sta.back().back()=='B' && s[i]=='C'){
                sta.back().push_back(s[i]);
                if(sta.back() == "ABC") sta.pop_back();
            }else{
                sta.push_back({s[i]});
            }
        }else{
            sta.push_back({s[i]});
        }
        i++;
    }
    string ans = "";
    rep(i,sta.size()) ans += sta[i];
    cout << ans << el;
    return 0;
}
