// C - Shopping Street
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

int n;
int f[105][10], p[105][11];
int ans = -INF;

void calc_score(const vector<int>& a){
    int zero = 0;
    rep(i,10) if(a[i] == 0) zero++;
    if(zero == 10) return;
    int sum = 0;
    rep(i,n){
        int cnt = 0;
        rep(j,10) if(f[i][j] && a[j]) cnt++;
        sum += p[i][cnt];
    }
    ans = max(ans, sum);
}

void rec(vector<int>& a){
    if((int)a.size() == 10){
        calc_score(a);
        return;
    }
    // 配列に0を入れる場合
    a.push_back(0);
    rec(a);
    a.pop_back();
    // 配列に1を入れる場合
    a.push_back(1);
    rec(a);
    a.pop_back();
    return;
}

// NOTE: bit全探索でも解ける
int main(){
    cin >> n;
    rep(i,n)rep(j,10) cin >> f[i][j];
    rep(i,n)rep(j,11) cin >> p[i][j];
    vector<int> a;
    rec(a);
    cout << ans << el;
    return 0;
}
