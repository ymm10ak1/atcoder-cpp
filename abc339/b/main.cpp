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

const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

int main(){
    int h, w, n;
    cin >> h >> w >> n;
    vector<string> s(h,string(w,'.'));
    int x = 0, y = 0;
    int k = 0;
    while(n--){
        if(s[x][y] == '.'){
            s[x][y] = '#';
            k = (k+1)%4;
            x = (x+dx[k])%h;
            if(x < 0) x += h;
            y = (y+dy[k])%w;
            if(y < 0) y += w;
        }else{
            s[x][y] = '.';
            k = (k-1)%4;
            if(k < 0) k += 4;
            x = (x+dx[k])%h;
            if(x < 0) x += h;
            y = (y+dy[k])%w;
            if(y < 0) y += w;
        }
    }
    rep(i,h) cout << s[i] << el;
    return 0;
}
