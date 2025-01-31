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
    int n;
    string td;
    cin >> n >> td;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<int> ans;
    rep(i,n){
        if(s[i].size() == td.size()){
            if(s[i] == td) ans.push_back(i+1);
            else{
                int cnt = 0;
                rep(j,s[i].size()) if(s[i][j] != td[j]) cnt++;
                if(cnt == 1) ans.push_back(i+1);
            }
        }else if(s[i].size()-td.size() == 1){
            int idx = 0, cnt = 0;
            rep(j,s[i].size()){
                if(idx<td.size() && s[i][j]==td[idx]) idx++;
                else cnt++;
            }
            if(idx==td.size() && cnt==1) ans.push_back(i+1);
        }else if(td.size()-s[i].size() == 1){
            int idx = 0, cnt = 0;
            rep(j,td.size()){
                if(idx<s[i].size() && td[j]==s[i][idx]) idx++;
                else cnt++;
            }
            if(idx==s[i].size() && cnt==1) ans.push_back(i+1);
        }
    }
    cout << ans.size() << el;
    rep(i,ans.size()) printf("%d%c", ans[i], i==(int)ans.size()-1?'\n':' ');
    return 0;
}
