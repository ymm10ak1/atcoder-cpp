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

int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    rep(i,h)rep(j,w){
        if(s[i][j] == '.'){
            int cnt = 0;
            rep(k,4){
                int ni = i+dx[k], nj = j+dy[k];
                if(ni<0 || ni>=h || nj<0 || nj>=w) continue;
                if(s[ni][nj] == '#') cnt++;
            }
            if(cnt >= 2){
                printf("%d %d\n", i+1, j+1);
                return 0;
            }
        }
    }
    return 0;
}
