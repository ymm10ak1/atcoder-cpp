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
    vector<bool> a(101);
    rep(i,n){
        int ai; cin >> ai;
        a[ai] = true;
    }
    int cnt = 0;
    rrep(i,101,0){
        if(a[i]){
            if(cnt){
                cout << i << el;
                return 0;
            }else{
                cnt++;
            }
        }
    }
    return 0;
}
