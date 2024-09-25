// D
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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    stack<pair<int,int>> st;
    vector<int> ans;
    int cnt = 0;
    rep(i,n){
        if(st.size()>0 && st.top().first==a[i]){
            st.top().second++;
            if(st.top().second == st.top().first){
                cnt = max(0,cnt-st.top().second+1);
                st.pop();
            }else{
                cnt++;
            }
        }else{
            st.push({a[i],1});
            cnt++;
        }
        ans.push_back(cnt);
    }
    for(int x : ans) cout << x << el;
    return 0;
}
