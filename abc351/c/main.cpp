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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> sta;
    rep(i,n){
        if(sta.size() == 0){
            sta.push_back(a[i]);
        }else{
            int x = a[i];
            if(sta.back() == a[i]){
                while(sta.size()>0 && sta.back()==x){
                    x = x+1;
                    sta.pop_back();
                }
            }
            sta.push_back(x);
        }
    }
    cout << sta.size() << el;
    return 0;
}
