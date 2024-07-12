// 076 - Cake Cut（★3）
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
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll suma = 0;
    rep(i,n) suma += a[i];
    ll sum = 0, x = suma/10;
    int r = 0;
    rep(l,n){
        // x(aの総和/10)以下を満たすrを求める
        while(r<2*n && sum+a[r%n]<=x){
            sum += a[r%n];
            r++;
            // 区間[l,r)のaの総和がちょうどxのとき終了する
            if(sum == x){
                cout << "Yes" << el;
                return 0;
            }
        }
        if(l == r) r++;
        else sum -= a[l];
    }
    cout << "No" << el;
    return 0;
}