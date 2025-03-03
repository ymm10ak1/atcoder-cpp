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
        dat.resize(2*siz,0);
    }

    void update(int pos, int x){
        pos += siz-1;
        dat[pos] = x;
        while(pos > 1){
            pos /= 2;
            dat[pos] = max(dat[pos*2], dat[pos*2+1]);
        }
    }

    int query(int l, int r, int a, int b, int u){
        if(r<=a || b<=l) return 0;
        if(l<=a && b<=r) return dat[u];
        int m = (a+b)/2;
        int vl = query(l, r, a, m, 2*u);
        int vr = query(l, r, m, b, 2*u+1);
        return max(vl, vr);
    }
};

int main(){
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    int mx = 0;
    rep(i,n){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    SegmentTree seg(mx);
    vector<int> cnt(n);
    rep(i,n){
        int al = max(1, a[i]-d);
        int ar = min(500005, a[i]+d);
        int x = seg.query(al, ar+1, 1, seg.siz+1, 1)+1;
        cnt[i] = x;
        seg.update(a[i], x);
    }
    int ans = 0;
    rep(i,n) ans = max(ans, cnt[i]);
    cout << ans << el;
    return 0;
}
