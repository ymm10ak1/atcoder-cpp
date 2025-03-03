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
    int n; cin >> n;
    vector<int> d(n);
    rep(i,n) cin >> d[i];
    int ans = 0;
    rep(i,n){
        repi(j,1,d[i]+1){
            set<int> st;
            int m = i+1;
            while(m){
                st.insert(m%10);
                m /= 10;
            }
            int day = j;
            while(day){
                st.insert(day%10);
                day /= 10;
            }
            if(st.size() == 1) ans++;
        }
    }
    cout << ans << el;
    return 0;
}
