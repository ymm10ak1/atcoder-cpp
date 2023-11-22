// C - City Savers
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = n-1; i >= s; --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1), b(n);
    rep(i, n+1) cin >> a[i];
    rep(i, n) cin >> b[i];
    ll ans = 0;
    rep(i, n){
        // NOTE: ここのif文の条件をmin()関数を使用すればもう少し簡潔に実装できそう
        if(a[i] > b[i]){
            ans += b[i];
        }else{
            b[i] -= a[i];
            ans += a[i];
            // NOTE: こちらのif文もmin()関数に変更したほうがよい
            if(a[i+1] <= b[i]){
                ans += a[i+1];
                a[i+1] = 0;
            }else{
                a[i+1] -= b[i];
                ans += b[i];
            }
        }
    }
    cout << ans << el;
    return 0;
}