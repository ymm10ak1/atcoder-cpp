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
using PP = pair<ll,pair<int,int>>;

int main(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<vector<int>> d(n,vector<int>(n));
    rep(i,n)rep(j,n) cin >> d[i][j];

    priority_queue<PP,vector<PP>,greater<PP>> q;
    vector<ll> dist(2*n,LLINF);
    q.push({0,{0,0}});
    dist[0] = 0;

    while(!q.empty()){
        auto [cost, now] = q.top(); q.pop();
        if(now.second == 0){
            rep(i,2*n){
                if(now.first%n == i%n) continue;
                if(dist[i] > cost+(ll)d[now.first%n][i%n]*a){
                    dist[i] = cost+(ll)d[now.first%n][i%n]*a;
                    q.push({cost+(ll)d[now.first%n][i%n]*a, {i, 0}});
                }
            }
        }
        repi(i,n,2*n){
            if(now.first%n == i%n) continue;
            if(dist[i] > cost+(ll)d[now.first%n][i%n]*b+c){
                dist[i] = cost+(ll)d[now.first%n][i%n]*b+c;
                q.push({cost+(ll)d[now.first%n][i%n]*b+c, {i, 1}});
            }
        }
    }
    cout << dist[2*n-1] << el;
    return 0;
}
