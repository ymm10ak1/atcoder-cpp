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
    int a = -1, b = -1, c = -1;
    rep(i,n){
        if(s[i]=='A' && a==-1) a = i+1;
        if(s[i]=='B' && b==-1) b = i+1;
        if(s[i]=='C' && c==-1) c = i+1;
        if(a>=0 && b>=0 && c>=0){
            cout << max({a,b,c}) << el;
            return 0;
        }
    }
    return 0;
}
