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
    ll sx, sy;
    cin >> n >> m >> sx >> sy;
    vector<ll> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    vector<char> d(m);
    vector<int> c(m);
    rep(i,m) cin >> d[i] >> c[i];
    map<ll,set<ll>> mp1, mp2;
    rep(i,n){
        mp1[x[i]].insert(y[i]);
        mp2[y[i]].insert(x[i]);
    }
    int cnt = 0;
    rep(i,m){
        if(d[i] == 'U'){
            ll ny = sy + c[i];
            auto itr = mp1[sx].lower_bound(sy);
            for(auto it=itr; it!=mp1[sx].end();){
                if(*it <= ny){
                    mp2[*it].erase(sx);
                    it = mp1[sx].erase(it);
                    cnt++;
                }else{
                    break;
                }
            }
            sy = ny;
        }else if(d[i] == 'D'){
            ll ny = sy - c[i];
            auto itr = mp1[sx].lower_bound(ny);
            for(auto it=itr; it!=mp1[sx].end();){
                if(*it <= sy){
                    mp2[*it].erase(sx);
                    it = mp1[sx].erase(it);
                    cnt++;
                }else{
                    break;
                }
            }
            sy = ny;
        }else if(d[i] == 'L'){
            ll nx = sx - c[i];
            auto itr = mp2[sy].lower_bound(nx);
            for(auto it=itr; it!=mp2[sy].end();){
                if(*it <= sx){
                    mp1[*it].erase(sy);
                    it = mp2[sy].erase(it);
                    cnt++;
                }else{
                    break;
                }
            }
            sx = nx;
        }else if(d[i] == 'R'){
            ll nx = sx + c[i];
            auto itr = mp2[sy].lower_bound(sx);
            for(auto it=itr; it!=mp2[sy].end();){
                if(*it <= nx){
                    mp1[*it].erase(sy);
                    it = mp2[sy].erase(it);
                    cnt++;
                }else{
                    break;
                }
            }
            sx = nx;
        }
    }
    printf("%lld %lld %d\n", sx, sy, cnt);
    return 0;
}
