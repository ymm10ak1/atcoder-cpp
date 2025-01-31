#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i,m) cin >> a[i];
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<int> score(n);
    int maxs = 0;
    rep(i,n){
        score[i] = i+1;
        rep(j,m) if(s[i][j] == 'o') score[i] += a[j];
        maxs = max(maxs, score[i]);
    }
    vector<P> vp;
    rep(i,m) vp.emplace_back(a[i],i);
    sort(rall(vp));
    rep(i,n){
        int cur = score[i];
        int cnt = 0;
        if(cur < maxs){
            rep(j,m){
                int nj = vp[j].second;
                if(s[i][nj] == 'x'){
                    cnt++;
                    cur += vp[j].first;
                }
                if(cur > maxs) break;
            }
        }
        cout << cnt << el;
    }
    return 0;
}
