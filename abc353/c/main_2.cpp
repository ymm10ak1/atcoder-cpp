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

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    ll l = 0;
    rep(i,n) l += a[i];
    l *= (n-1);
    const int M = 1e8;
    ll cntu = 0, cntd = 0;
    rep(i,n){
        if(a[i] >= M/2){
            cntu++;
            continue;
        }
        int idx = lower_bound(all(a),M-a[i])-a.begin();
        cntd += n-idx;
    }
    ll r = (cntd+(cntu*(cntu-1)/2))*M;
    cout << l-r << el;
    return 0;
}
