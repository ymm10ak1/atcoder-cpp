// 
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
    int n;
    ll s;
    cin >> n >> s;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> b(2*n);
    rep(i,2*n) b[i] = a[i%n];
    ll num = 0;
    rep(i,n) num += a[i];
    ll ama = s%num;
    if(ama == 0){
        cout << "Yes" << el;
        return 0;
    }
    int r = 0;
    ll sum = 0;
    rep(l,2*n){
        while(r<2*n && sum+b[r]<=ama){
            sum += b[r];
            r++;
        }
        if(sum == ama){
            cout << "Yes" << el;
            return 0;
        }
        if(l == r) r++;
        else sum -= b[l];
    }
    cout << "No" << el;
    return 0;
}
