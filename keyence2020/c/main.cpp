// C - Subarray Sum
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
    int n,k,s;
    cin >> n >> k >> s;
    rep(i,n){
        if(i<k){
            printf("%d%c",s,i==n-1?'\n':' ');
        }else{
            int ss = s+1;
            if(s == INF) ss = s-1;
            printf("%d%c",ss,i==n-1?'\n':' ');
        }
    }
    return 0;
}
