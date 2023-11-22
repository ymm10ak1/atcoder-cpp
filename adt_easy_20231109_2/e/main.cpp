// 
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
    int n;
    cin >> n;
    vector<string> s(n);
    map<string, int> mp;
    vector<string> res;
    rep(i, n){
        cin >> s[i];
        if(mp[s[i]] == 0){
            res.push_back(s[i]);
            mp[s[i]]++;
        }else{
            string t = s[i]+"("+to_string(mp[s[i]])+")";
            mp[s[i]]++;
            res.push_back(t);
        }
    }
    rep(i, res.size()){
        cout << res[i] << el;
    }
    return 0;
}