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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    sort(all(s));
    do{
        bool ok = true;
        rep(i,n-1){
            int cnt = 0;
            rep(j,m){
                if(s[i][j] != s[i+1][j]) cnt++;
            }
            if(cnt > 1) ok = false;
        }
        if(ok){
            cout << "Yes" << el;
            return 0;
        }
    }while(next_permutation(all(s)));
    cout << "No" << el;
    return 0;
}
