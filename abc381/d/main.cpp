// 
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
    vector<pair<int,int>> vp;
    for(int i=0; i<n;){
        int j = i+1;
        while(j<n && a[i]==a[j]) j++;
        vp.emplace_back(a[i],j-i);
        i = j;
    }
    int m = vp.size();
    int r = 0, ans = 0;
    set<int> st, over3;
    rep(l,m){
        bool flag = false;
        if(vp[l].second >= 3){
            over3.insert(vp[l].first);
            flag = true;
        }
        while(r<m && vp[r].second>=2){
            if(st.count(vp[r].first) == 1) break;
            if(!flag && over3.size() == 1) break;
            st.insert(vp[r].first);
            if(vp[r].second >= 3){
                over3.insert(vp[r].first);
                r++;
                if(flag && over3.size()==2) break;
            }else{
                r++;
            }
        }
        ans = max(ans, (r-l)*2);
        if(l == r) r++;
        if(st.count(vp[l].first) == 1) st.erase(vp[l].first);
        if(over3.count(vp[l].first) == 1) over3.erase(vp[l].first);
    }
    cout << ans << el;
    return 0;
}
