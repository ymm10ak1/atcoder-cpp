#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> l(n);
    ll sum = 0;
    rep(i,n){
        cin >> l[i];
        sum += l[i];
    }
    ll ng = 0, ok = sum+n;
    while(abs(ok-ng) > 1){
        ll mid = (ok+ng)/2;
        ll x = 0;
        int cnt = 0;
        bool flag = true;
        rep(i,n){
            if(x+l[i] <= mid){
                x += l[i]+1;
            }else{
                cnt++;
                if(l[i] <= mid) x = l[i]+1;
                else flag = false;
            }
        }
        if(cnt >= m) flag = false;
        if(flag) ok = mid;
        else ng = mid;
    }
    cout << ok << el;
    return 0;
}
