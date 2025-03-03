#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    string s, t;
    cin >> s >> t;
    reverse(all(s));
    reverse(all(t));
    vector<int> ans;
    int i = 1;
    while(t.size() > 0){
        if(t.size()>0 && s.size()>0 && t.back()==s.back()){
            ans.push_back(i);
            s.pop_back();
        }
        t.pop_back();
        i++;
    }
    rep(i,ans.size()) printf("%d%c", ans[i], i==(int)ans.size()-1?'\n':' ');
    return 0;
}
