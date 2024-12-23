// C - Snuke the Cookie Picker
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

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int minh=INF, maxh=0, minw=INF, maxw=0;
    rep(i,h)rep(j,w){
        if(s[i][j] == '#'){
            minh = min(minh,i);
            maxh = max(maxh,i);
            minw = min(minw,j);
            maxw = max(maxw,j);
        }
    }
    for(int i=minh; i<=maxh; ++i){
        for(int j=minw; j<=maxw; ++j){
            if(s[i][j] == '.'){
                cout << i+1 << " " << j+1 << el;
                return 0;
            }
        }
    }
    return 0;
}
