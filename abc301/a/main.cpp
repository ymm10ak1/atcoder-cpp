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
    int t = 0, a = 0;
    int tidx = 0, aidx = 0;
    rep(i,n){
        if(s[i] == 'T'){
            t++;
            tidx = i;
        }else{
            a++;
            aidx = i;
        }
    }
    char ans = ' ';
    if(t > a){
        ans = 'T';
    }else if(t < a){
        ans = 'A';
    }else{
        if(tidx < aidx) ans = 'T';
        else ans = 'A';
    }
    cout << ans << el;
    return 0;
}
