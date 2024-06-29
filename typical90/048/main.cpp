// 048 - I will not drop out（★3）
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

// NOTE: まだ解いてない
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    vector<pair<int,int>> vpa, vpb;
    rep(i,n) vpa.push_back({a[i], i});
    rep(i,n) vpa.push_back({b[i], i});
    sort(rall(a));
    sort(rall(b));
    vector<bool> used(n,false);
    int ai = 0, bi = 0;
    ll ans = 0;
    while(k > 0){
        if(k >= 2){
            int ai1 = vpa[ai].second;
            int bi1 = vpb[bi].second, bi2 = vpb[bi+1].second;
            // そのa[i]がすでに使用されているか
            if(vpa[ai].first >= vpb[bi].first+vpb[bi+1].first){
            }
        }else{
        }
    }
    return 0;
}
