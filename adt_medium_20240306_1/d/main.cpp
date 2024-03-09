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

void print_arr(const vector<string>& arr){
    rep(i,arr.size()){
        cout << arr[i] << el;
    }
}

bool check(const vector<string>& ns){
    rep(i,3){
        rep(j,3){
            if(ns[i][j] == '.') return false;
            if(ns[8-i][8-j] == '.') return false;
        }
    }
    rep(i,4){
        rep(j,4){
            if(i<3 && j==3){
                if(ns[i][j] == '#') return false;
                if(ns[8-i][8-j] == '#') return false;
            }else if(i==3){
                if(ns[i][j] == '#') return false;
                if(ns[8-i][8-j] == '#') return false;
            }
        }
    }
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<pair<int, int>> res;
    rep(i,n-8){
        vector<string> a(9);
        rep(j,m-8){
            rep(k,9){ a[k] = s[i+k].substr(j,9); }
            if(check(a)) res.push_back({i+1, j+1});
        }
    }
    if(res.size() != 0) rep(i,res.size()) cout << res[i].first << " " << res[i].second << el;
    else cout << el;
    return 0;
}