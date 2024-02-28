// B52 - Ball Simulation
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
    int n, x;
    string a;
    cin >> n >> x >> a;
    queue<int> q;
    q.push(x-1);
    a[x-1] = '@';
    while(!q.empty()){
        int pos = q.front(); q.pop();
        if(pos-1>=0 && a[pos-1]=='.'){
            a[pos-1] = '@';
            q.push(pos-1);
        }
        if(pos+1<n && a[pos+1]=='.'){
            a[pos+1] = '@';
            q.push(pos+1);
        }
    }
    cout << a << el;
    return 0;
}