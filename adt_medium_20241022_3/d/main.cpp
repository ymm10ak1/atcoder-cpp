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
    int n;
    string t;
    cin >> n >> t;
    int dire = 0;
    vector<pair<int,int>> dires = {{1,0},{0,-1},{-1,0},{0,1}};
    int x = 0, y = 0;
    rep(i,n){
        if(t[i] == 'S'){
            x += dires[dire].first;
            y += dires[dire].second;
        }else{
            dire = (dire+1)%4;
        }
    }
    cout << x << " " << y << el;
    return 0;
}
