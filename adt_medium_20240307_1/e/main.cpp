// 
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
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<pair<int,int>> vp;
    rep(i,m){
        cin >> a[i];
        vp.push_back({a[i],i});
    }
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    int max_score = 0;
    vector<int> scores(n);
    rep(i,n){
        int v = 0;
        rep(j,m) if(s[i][j] == 'o') v+=a[j];
        scores[i] = v+i+1;
        max_score = max(max_score, v+i+1);
    }
    sort(rall(vp));
    rep(i,n){
        int cnt = 0;
        rep(j,n){
            if(i == j) continue;
            if(scores[i] > scores[j]) ++cnt;
        }
        if(cnt == n-1){
            cout << 0 << el;
            continue;
        }
        int v = scores[i]; cnt = 0;
        rep(j,vp.size()){
            if(s[i][vp[j].second] == 'x'){
                v += vp[j].first;
                ++cnt;
                if(v > max_score){
                    cout << cnt << el;
                    break;
                }
            }
        }
    }
    return 0;
}