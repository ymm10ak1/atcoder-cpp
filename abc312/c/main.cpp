#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    sort(all(a));
    sort(all(b));
    // NOTE: ここの二分探索はいらないかも
    int prev = 0, x = 0;
    bool flag = false;
    rep(i,m){
        int idx = upper_bound(all(a),b[i])-a.begin();
        int bcnt = m-i, acnt = idx;
        if(acnt >= bcnt){
            x = b[i];
            if(i > 0) prev = b[i-1];
            flag = true;
            break;
        }
    }
    if(!flag){
        prev = b[m-1];
        x = a[0];
    }

    auto check = [&](int key){
        int aidx = upper_bound(all(a),key)-a.begin();
        int bidx = lower_bound(all(b),key)-b.begin();
        if(aidx >= m-bidx) return true;
        return false;
    };

    int ng = prev-1, ok = x+1;
    while(abs(ok-ng) > 1){
        int mid = (ok+ng)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << el;
    return 0;
}
