// B - ss
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
    string s; cin >> s;
    repi(i,1,s.size()-1){
        string ss = s.substr(0,(int)s.size()-i);
        int slen = ss.size();
        if(slen%2 == 0){
            string s1 = ss.substr(0,slen/2);
            string s2 = ss.substr(slen/2,slen/2);
            if(s1 == s2){
                cout << slen << el;
                return 0;
            }
        }
    }
    return 0;
}
