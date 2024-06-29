// C - Exam and Wizard
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

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    ll suma = 0, sumb = 0;
    int cnt = 0;
    vector<bool> check(n,false);
    rep(i,n){
        if(a[i] < b[i]){
            cnt++;
            suma += a[i];
            sumb += b[i];
            check[i] = true;
        }
    }
    // 1回もa[i] < b[i]を満たしていない場合、すべてa[i] >= b[i]を満たしているので0が出力される
    if(suma >= sumb){
        cout << cnt << el;
        return 0;
    }
    vector<pair<int, int>> diff;
    rep(i,n){
        if(check[i]) continue;
        diff.push_back({abs(a[i]-b[i]),i});
    }
    sort(rall(diff));
    rep(i,diff.size()){
        int j = diff[i].second;
        suma += a[j];
        sumb += b[j];
        ++cnt;
        if(suma >= sumb){
            cout << cnt << el;
            return 0;
        }
    }
    cout << -1 << el;
    return 0;
}
