// C - Connect 6
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

const int dx[] = {-1,-1,-1,0,0,1,1,1};
const int dy[] = {-1,0,1,-1,1,-1,0,1};

bool check(const vector<string>& s, int sx, int sy){
    int n = s.size();
    rep(i,8){
        string ss = "";
        ss += s[sx][sy];
        int nx = sx+dx[i], ny = sy+dy[i];
        rep(j,5){
            if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
            ss += s[nx][ny];
            nx += dx[i], ny += dy[i];
        }
        if(ss.size() == 6){
            int cnt = 0;
            rep(j,6) if(ss[j] == '.') cnt++;
            if(cnt <= 2) return true;
        }
    }
    return false;
}

int main(){
    int n; cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    rep(i,n){
        rep(j,n){
            if(s[i][j] == '#'){
                if(check(s,i,j)){
                    cout << "Yes" << el;
                    return 0;
                }
            }
        }
    }
    cout << "No" << el;
    return 0;
}
