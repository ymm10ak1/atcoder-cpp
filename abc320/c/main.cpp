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
    int m, n = 3;
    string s[n];
    cin >> m;
    rep(i,n) cin >> s[i];
    int ans = INF;
    rep(i,10){
        vector<int> minx(n,-1);
        rep(j,3*m){
            rep(k,n){
                if(s[k][j%m] == i+'0'){
                    if(minx[k] == -1){
                        minx[k] = j;
                    }else{
                        int cnt = 0;
                        rep(l,n){
                            if(k!=l && minx[k]==minx[l]) cnt++;
                        }
                        if(cnt >= 1) minx[k] = j;
                    }
                }
            }
        }
        bool ok = true;
        rep(j,n) if(minx[j] == -1) ok = false;
        if(!ok) continue;
        int maxx = 0;
        rep(j,n) maxx = max(maxx,minx[j]);
        ans = min(ans, maxx);
    }
    cout << (ans==INF?-1:ans) << el;
    return 0;
}
