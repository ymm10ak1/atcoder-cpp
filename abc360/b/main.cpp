// B - Vertical Reading
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
    string s, t;
    cin >> s >> t;
    repi(i,1,s.size()){
        vector<string> ss;
        for(int j=0; j<(int)s.size(); j+=i) ss.push_back(s.substr(j,i));
        repi(c,1,i+1){
            string tt = "";
            rep(k,ss.size()){
                if((int)ss[k].size() >= c){
                    tt += ss[k][c-1];
                }
            }
            if(tt == t){
                cout << "Yes" << el;
                return 0;
            }
        }
    }
    cout << "No" << el;
    return 0;
}