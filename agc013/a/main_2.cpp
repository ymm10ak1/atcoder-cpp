// A - Sorted Arrays
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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int ans = 0;
    bool incre = false, decre = false;
    rep(i, n-1){
        if(a[i] > a[i+1]) incre = true;
        if(a[i] < a[i+1]) decre = true;
        if(incre && decre){
            ++ans;
            incre = false; decre = false;
        }
    }
    ++ans;
    cout << ans << el;
    return 0;
}