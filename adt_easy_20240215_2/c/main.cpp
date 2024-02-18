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
    repi(i,n,1000){
        string s = to_string(i);
        int n1 = int(s[0]-'0');
        int n2 = int(s[1]-'0');
        int n3 = n1*n2;
        if(n3 == int(s[2]-'0')){
            cout << i << el;
            return 0;
        }
    }
    return 0;
}