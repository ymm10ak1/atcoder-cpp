// 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = n-1; i >= s; --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n; cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    rep(i,n){
        rep(j,n){
            if(i == j) continue;
            string ns = s[i]+s[j];
            string t = ns;
            reverse(all(t));
            if(ns == t){
                cout << "Yes" << el;
                return 0;
            }
        }
    }
    cout << "No" << el;
    return 0;
}