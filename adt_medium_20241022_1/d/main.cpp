// D
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

const vector<string> tak = {
    "###.?????",
    "###.?????",
    "###.?????",
    "....?????",
    "?????????",
    "?????....",
    "?????.###",
    "?????.###",
    "?????.###",
};

bool check(const vector<string>& s, int sx, int sy){
    rep(i,9){
        rep(j,9){
            if(tak[i][j]=='#' && s[sx+i][sy+j]!='#') return false;
            if(tak[i][j]=='.' && s[sx+i][sy+j]!='.') return false;
        }
    }
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<pair<int,int>> ans;
    rep(i,n-8){
        rep(j,m-8){
            if(check(s, i, j)) ans.push_back({i+1,j+1});
        }
    }
    rep(i,ans.size()) cout << ans[i].first << " " << ans[i].second << el; 
    return 0;
}
