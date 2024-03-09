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
    string x;
    rep(i,4) cin >> x;
    if(x[0]==x[1] && x[1]==x[2] && x[2]==x[3] && x[3]==x[0]){
        cout << "Weak" << el;
        return 0;
    }
    vector<bool> weaks(3,false);
    rep(i,3){
        int x0 = x[i]-'0', x1 = x[i+1]-'0';
        if(x0 < 9){
            if(x1-x0 == 1) weaks[i] = true;
            else weaks[i] = false;
        }else if(x0 == 9){
            if(x1 == 0) weaks[i] = true;
            else weaks[i] = false;
        }
    }
    int cnt = 0;
    rep(i,3) if(weaks[i]) ++cnt;
    if(cnt == 3) cout << "Weak" << el;
    else cout << "Strong" << el;
    return 0;
}