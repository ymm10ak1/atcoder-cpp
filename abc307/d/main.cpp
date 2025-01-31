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
    int n;
    string s;
    cin >> n >> s;
    vector<int> l;
    set<int> r;
    rep(i,n){
        if(s[i] == '(') l.push_back(i);
        if(s[i] == ')') r.insert(i);
    }
    sort(rall(l));
    vector<int> check(n);
    rep(i,l.size()){
        auto it = r.lower_bound(l[i]);
        if(it != r.end()){
            check[l[i]] = 1;
            check[*it] = 2;
            r.erase(*it);
        }
    }
    string ans = "";
    int cnt = 0;
    rep(i,n){
        if(check[i] == 1){
            cnt++;
        }else if(check[i] == 2){
            cnt--;
        }else if(check[i] == 0){
            if(cnt > 0) continue;
            else ans += s[i];
        }
    }
    cout << ans << el;
    return 0;
}
