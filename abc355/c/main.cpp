// C - Bingo 2
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
    int n, t;
    cin >> n >> t;
    vector<int> a(t);
    rep(i,t){
        cin >> a[i];
        a[i]--;
    }
    vector<int> row(n), col(n), naname(2);
    rep(i,t){
        int r = a[i]/n;
        int c = a[i]%n;
        bool ok = false;
        if(++row[r]==n || ++col[c]==n) ok = true;
        if(r==c && ++naname[0]==n) ok = true;
        if(n-1-r==c && ++naname[1]==n) ok = true;
        if(ok){
            cout << i+1 << el;
            return 0;
        }
    }
    cout << -1 << el;
    return 0;
}
