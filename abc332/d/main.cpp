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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h,vector<int>(w)), b(h,vector<int>(w));
    rep(i,h)rep(j,w) cin >> a[i][j];
    rep(i,h)rep(j,w) cin >> b[i][j];

    vector<int> r(h), c(w);
    rep(i,h) r[i] = i;
    rep(i,w) c[i] = i;
    int ans = INF;

    auto cnt = [&](int n, const vector<int>& vec) -> int{
        vector<int> idx(n);
        rep(i,n) idx[i] = i;
        int cnt = 0;
        rrep(i,n,0){
            int sta = 0, end = i;
            rep(j,n){
                if(vec[i] == idx[j]) sta = j;
            }
            if(sta > end) swap(sta, end);
            repi(j,sta,end){
                swap(idx[j], idx[j+1]);
                cnt++;
            }
        }
        return cnt;
    };

    do{
        do{
            bool ok = true;
            rep(i,h)rep(j,w) if(a[r[i]][c[j]] != b[i][j]) ok = false;
            if(ok){
                int now = cnt(h, r);
                now += cnt(w, c);
                ans = min(ans, now);
            }
        }while(next_permutation(all(c)));
    }while(next_permutation(all(r)));
    cout << (ans==INF?-1:ans) << el;
    return 0;
}
