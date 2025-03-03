#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    rep(i,k) cin >> a[i];
    int ans = 0;
    if(k%2){
        int sum = 0;
        for(int i=1; i<k-1; i+=2) sum += a[i+1]-a[i];
        ans = sum;
        if(k >= 3){
            rep(i,k){
                if(i%2){
                    if(i+1 < k){
                        sum -= a[i+1]-a[i-1];
                        sum += a[i]-a[i-1];
                    }
                }else{
                    if(i+2 < k){
                        sum -= a[i+2]-a[i+1];
                        sum += a[i+2]-a[i];
                    }
                }
                ans = min(ans, sum);
            }
        }
    }else{
        for(int i=0; i<k-1; i+=2) ans += a[i+1]-a[i];
    }
    cout << ans << el;
    return 0;
}
