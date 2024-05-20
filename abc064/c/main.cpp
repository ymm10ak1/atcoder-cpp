// C - Colorful Leaderboatd
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

bool color[8];

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int cnt = 0;
    rep(i,n){
        if(1 <= a[i] && a[i] < 400) color[0] = true;
        else if(a[i] < 800) color[1] = true;
        else if(a[i] < 1200) color[2] = true;
        else if(a[i] < 1600) color[3] = true;
        else if(a[i] < 2000) color[4] = true;
        else if(a[i] < 2400) color[5] = true;
        else if(a[i] < 2800) color[6] = true;
        else if(a[i] < 3200) color[7] = true;
        else ++cnt;
    }
    int minAns = 0;
    rep(i,8) if(color[i]) ++minAns;
    int maxAns = minAns+cnt;
    // すべてのレートが3200以上の場合、1種類の色を作ることができる
    if(minAns == 0) minAns = 1;
    cout << minAns << " " << maxAns << el;
    return 0;
}
