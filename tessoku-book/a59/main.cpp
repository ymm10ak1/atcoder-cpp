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
        pos += sz;
        dat[pos] = x;
        while(pos > 1){
            pos /= 2;
            dat[pos] = dat[pos*2]+dat[pos*2+1];
        }
    }

    int query(int l, int r, int a, int b, int u){
        if(r<=a || b<=l) return 0;
        // 今見ている区間が求めたい区間に完全に含まれている場合は今のセルの値を返す
        if(l<=a && b<=r) return dat[u];
        int m = (a+b)/2;
        int vl = query(l, r, a, m, 2*u);
        int vr = query(l, r, m, b, 2*u+1);
        return vl+vr;
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    SegmentTree sg(n);
    rep(qi,q){
        int t; cin >> t;
        if(t == 1){
            int pos, x;
            cin >> pos >> x;
            sg.update(pos-1, x);
        }else{
            int l, r;
            cin >> l >> r;
            l--; r--;
            int sum = sg.query(l,r,0,sg.sz,1);
            cout << sum << el;
        }
    }
    return 0;
}
