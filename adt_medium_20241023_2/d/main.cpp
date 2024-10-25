// D
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
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<char> b(m);
    rep(i,m) cin >> a[i] >> b[i];
    vector<bool> taro(n);
    rep(i,m){
        if(!taro[a[i]-1] && b[i]=='M'){
            cout << "Yes" << el;
            taro[a[i]-1] = true;
        }else{
            cout << "No" << el;
        }
    }
    return 0;
}
