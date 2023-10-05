// B - Great Ocean View
#include<bits/stdc++.h>
#define repi(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i=n-1; i>=s; --i)
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    int ans = 1;
    int hi = h[0];
    rep(i, n-1){
        if(hi <= h[i+1]){
            ++ans;
            hi = h[i+1];
        }
    }
    printf("%d\n", ans);
    return 0;
}