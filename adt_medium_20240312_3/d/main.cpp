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
    int m; cin >> m;
    vector<int> d(m);
    int sum = 0;
    rep(i,m){
        cin >> d[i]; sum+=d[i];
    }
    int mid = (sum+1)/2;
    int v = 0;
    int month = 0, day = 0;;
    rep(i,m){
        if(v+d[i] < mid){
            v += d[i];
        }else{
            month = i+1;
            rep(j,d[i]+1){
                if(v+j == mid){
                    day = j;
                    cout << month << " " << day << el;
                    return 0;
                }
            }
        }
    }
    return 0;
}