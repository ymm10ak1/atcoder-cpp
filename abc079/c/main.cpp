// C - Train Ticket
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repi(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i=n-1; i>=s; --i)
#define repli(i, s, n) for(ll i=(s); i<(ll)(n); ++i)
#define repl(i, n) repli(i, 0LL, n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LINF = 1e18;

int main(){
    string s;
    cin >> s;
    string t = "";
    repl(bit, (1<<3)){
        int sum = s[0]-'0';
        t = s[0];
        // +: 1, -: 0
        rep(i, 3){
            if(bit&(1<<i)){
                sum += (s[i+1]-'0');
                t += '+';
            }else{
                sum -= (s[i+1]-'0');
                t += '-';
            }
            t += s[i+1];
        }
        if(sum == 7){
            cout << t << "=7" << el;
            return 0;
        }
    }
    return 0;
}