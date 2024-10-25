// C
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
    int n; cin >> n;
    vector<int> a(n), b(n-1);
    rep(i,n) cin >> a[i];
    rep(i,n-1) cin >> b[i];
    priority_queue<int> q1, q2;
    rep(i,n) q1.push(a[i]);
    rep(i,n-1) q2.push(b[i]);
    vector<int> c;
    while(!q1.empty()){
        if(!q2.empty()){
            int ai = q1.top();
            int bi = q2.top();
            if(bi >= ai){
                q1.pop();
                q2.pop();
            }else{
                q1.pop();
                c.push_back(ai);
            }
        }else{
            c.push_back(q1.top());
            q1.pop();
        }
    }
    if(c.size() >= 2) cout << -1 << el;
    else cout << c[0] << el;
    return 0;
}
