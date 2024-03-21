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
    vector<char> first_c = {'H','D','C','S'};
    vector<char> second_c = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    rep(i,s.size()){
        bool ok1 = false;
        rep(j,first_c.size()) if(s[i][0] == first_c[j]) ok1 = true;
        if(!ok1){
            cout << "No" << el;
            return 0;
        }
        ok1 = false;
        rep(j,second_c.size()) if(s[i][1] == second_c[j]) ok1 = true;
        if(!ok1){
            cout << "No" << el;
            return 0;
        }
    }
    rep(i,n){
        rep(j,n){
            if(i == j) continue;
            if(s[i] == s[j]){
                cout << "No" << el;
                return 0;
            }
        }
    }
    cout << "Yes" << el;
    return 0;
}