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

struct SegmentTree{
    vector<int> dat;
    int siz = 1;

    SegmentTree(int n){
        siz = 1;
        while(siz < n) siz *= 2;
        dat.assign(2*siz+1,INF);
    }

    void update(int pos, int x){
        pos += siz;
        dat[pos] = x;
        while(pos >= 2){
            pos /= 2;
            dat[pos] = min(dat[pos*2], dat[pos*2+1]);
        }
    }

    int query(int l, int r, int a, int b, int u){
        if(r<=a || b<=l) return INF;
        if(l<=a && b<=r) return dat[u];
        int m = (a+b)/2;
        int lval = query(l, r, a, m, 2*u);
        int rval = query(l, r, m, b, 2*u+1);
        return min(lval, rval);
    }
};

// 解説AC
int main(){
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> x(n);
    rep(i,n) cin >> x[i];

    SegmentTree seg(n);
    vector<int> dp(n,INF);
    dp[0] = 0;
    seg.update(0,0);
    repi(i,1,n){
        int li = lower_bound(all(x),x[i]-r)-x.begin();
        int ri = upper_bound(all(x),x[i]-l)-x.begin();

        // 半開区間[li, ri)の最小値を取得する
        dp[i] = seg.query(li,ri,0,seg.siz,1)+1;
        seg.update(i,dp[i]);
    }
    cout << dp[n-1] << el;
    return 0;
}
