// C - World Tour Finals
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
using P = pair<int,int>;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i,m) cin >> a[i];
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<P> scores;
    rep(i,n){
        int score = 0;
        rep(j,m) if(s[i][j] == 'o') score += a[j];
        scores.push_back({score+i+1,i});
    }
    vector<P> pa;
    rep(i,m) pa.push_back({a[i],i});
    sort(rall(scores));
    sort(rall(pa));
    vector<int> ans(n);
    int maxScore = scores[0].first;
    rep(i,scores.size()){
        if(i == 0) continue;
        int now = scores[i].first, p = scores[i].second;
        int cnt = 0;
        rep(j,pa.size()){
            if(s[p][pa[j].second] == 'x'){
                cnt++;
                now += pa[j].first;
                if(now > maxScore){
                    ans[p] = cnt;
                    break;
                }
            }
        }
    }
    for(int c : ans) cout << c << el;
    return 0;
}
