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
    vector<int> p(n);
    vector<vector<int>> f(n);
    vector<vector<bool>> kinou(n,vector<bool>(m));
    rep(i,n){
        cin >> p[i];
        int c; cin >> c;
        vector<int> fi(c);
        rep(j,c){
            cin >> fi[j];
            fi[j]--;
            kinou[i][fi[j]] = true;
        }
        f[i] = fi;
    }
    rep(i,n){
        rep(j,n){
            if(i == j) continue;
            if(p[i] >= p[j]){
                bool ok = true;
                rep(k,f[i].size()){
                    // j番目の商品がi番目の商品の機能をもっているか
                    if(!kinou[j][f[i][k]]) ok = false;
                }
                if(!ok) continue;
                int cnt = 0;
                rep(k,f[j].size()){
                    if(!kinou[i][f[j][k]]) cnt++;
                }
                if(cnt==0 && p[i]==p[j]) ok = false;
                if(ok){
                    cout << "Yes" << el;
                    return 0;
                }
            }
        }
    }
    cout << "No" << el;
    return 0;
}
