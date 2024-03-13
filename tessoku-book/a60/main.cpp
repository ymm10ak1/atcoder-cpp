// A60 - Stock Price
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
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qu;
    int cnt = 0;
    rep(d,n){
        if(d>0){
            bool check = false;
            while(!qu.empty()){
                if(a[d]<qu.top().first){
                    printf("%d%c",qu.top().second,d==n-1?'\n':' ');
                    qu.push({a[d],d+1});
                    check = true;
                    break;
                }else{
                    qu.pop();
                }
            }
            if(!check){
                qu.push({a[d],d+1});
                printf("-1%c",d==n-1?'\n':' ');
            }
        }else{
            cout << -1 << " ";
            qu.push({a[d],d+1});
        }
    }
    return 0;
}