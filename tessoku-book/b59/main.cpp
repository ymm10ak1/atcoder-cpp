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
    int sz = 1;

    SegmentTree(int n){
        sz = 1;
        while(sz < n) sz *= 2;
        dat.resize(2*sz,0);
    }

    void update(int pos, int x){
        pos += sz-1;
        dat[pos] = x;
        while(pos > 1){
            pos /= 2;
            dat[pos] = dat[pos*2]+dat[pos*2+1];
        }
    }

    int query(int l, int r, int a, int b, int u){
        if(r<=a || b<=l) return 0;
        if(l<=a && b<=r) return dat[u];
        int m = (a+b)/2;
        int vl = query(l, r, a, m, 2*u);
        int vr = query(l, r, m, b, 2*u+1);
        return vl+vr;
    }
};

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    // セグ木の最下段のindex(1~N)を利用する
    // 1番目から順に見てaの各値に対応するindexに1を記録する
    SegmentTree seg(n);
    ll ans = 0;
    rep(i,n){
        // aに1~Nが1回ずつしか現れないからこれでよかったが本当は求めたい区間を[a[i]+1, N+1)にしたほうがいい
        ans += seg.query(a[i],n+1,1,seg.sz+1,1);
        seg.update(a[i],1);
    }
    cout << ans << el;
    return 0;
}
