#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n; cin >> n;
    vector<int> a(n), c(n);
    rep(i,n) cin >> a[i] >> c[i];
    priority_queue<P> qa, qc;
    rep(i,n){
        qa.emplace(a[i],i);
        qc.emplace(c[i],i);
    }
    vector<bool> check(n);
    while(!qa.empty()){
        auto [ax, x] = qa.top(); qa.pop();
        while(!qc.empty()){
            auto [cy, y] = qc.top();
            if(ax == a[y]){
                qc.pop();
            }else if(ax>a[y] && c[x]<cy){
                check[y] = true;
                qc.pop();
            }else{
                break;
            }
        }
    }
    int cnt = 0;
    rep(i,n) if(!check[i]) cnt++;
    cout << cnt << el;
    rep(i,n){
        if(!check[i]){
            cout << i+1;
            if(i < n-1) cout << " ";
        }
        if(i == n-1) cout << el;
    }
    return 0;
}
