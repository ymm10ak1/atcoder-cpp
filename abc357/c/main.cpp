// C - Sierpinski carpet
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
    vector<int> v;
    int d = 1;
    v.push_back(d);
    rep(i,n){
        d *= 3;
        v.push_back(d);
    }
    string s = "";
    rep(i,d) s += '#';
    vector<string> ans(d,s);
    repi(k,1,v.size()){
        for(int i=v[k-1]; i<d; i+=v[k]){
            for(int j=v[k-1]; j<d; j+=v[k]){
                for(int l=i; l<i+v[k-1]; ++l){
                    for(int m=j; m<j+v[k-1]; ++m){
                        ans[l][m] = '.';
                    }
                }
            }
        }
    }
    rep(i,d) cout << ans[i] << el;
    return 0;
}
