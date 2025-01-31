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

vector<vector<int>> a;
int n, m, r, cnt;

void f(int x, int y, vector<int> v, bool flag){
    if(x<n && y<r) v.push_back(a[x][y]);
    if((int)v.size() == n){
        if(flag)rep(i,n) printf("%d%c", v[i], i==(int)v.size()-1?'\n':' ');
        else cnt++;
        v.pop_back();
    }
    if(x+1 < n){
        f(x+1,y,v,flag);
        v.pop_back();
    }
    if(y+1 < r){
        f(x,y+1,v,flag);
        v.pop_back();
    }
}

int main(){
    cin >> n >> m;
    r = m%10;
    if(r == 0) r = 10;
    rep(i,n){
        vector<int> v;
        repi(j,1,r+1) v.push_back(i*10+j);
        a.push_back(v);
    }
    vector<int> v;
    f(0,0,v,false);
    cout << cnt << el;
    f(0,0,v,true);
    return 0;
}
