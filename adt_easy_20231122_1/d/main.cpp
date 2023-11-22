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

bool check(const vector<string>& s){
    bool ok = true;
    rep(i, 4){
        rep(j, 4){
            if(i==3 || j==3){
                if(s[i][j] != '.') ok = false;
            }else{
                if(s[i][j] != '#') ok = false;
            }
        }
    }
    repi(i, 5, 9){
        repi(j, 5, 9){
            if(i == 5 || j==5){
                if(s[i][j] != '.') ok = false;
            }else{
                if(s[i][j] != '#') ok = false;
            }
        }
    }
    return ok;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    vector<pair<int, int>> res;
    int st = 0;
    rep(i, m-8){
        int st = 0;
        rep(j, n-8){
            vector<string> ss;
            rep(k, 9){
                string t = s[j+k].substr(i, 9);
                ss.push_back(t);
            }
            if(check(ss)){
                res.push_back({j+1, i+1});
            }
        }
    }
    sort(all(res));
    if(res.size() == 0){
        cout << el;
    }else{
        for(pair<int, int> p : res) cout << p.first << " " << p.second << el;
    }
    return 0;
}