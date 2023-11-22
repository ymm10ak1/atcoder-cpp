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
    string s;
    cin >> s;
    int y = s[s.size()-1]-'0';
    if(y <= 2){
        rep(i, s.size()){
            if(s[i] == '.'){
                cout << "-" << el;
                break;
            }
            cout << s[i];
        }
    }else if(y <= 6){
        rep(i, s.size()){
            if(s[i] == '.'){
                cout << el;
                break;
            }
            cout << s[i];
        }
    }else{
        rep(i, s.size()){
            if(s[i] == '.'){
                cout << "+" << el;
                break;
            }
            cout << s[i];
        }
    }
    return 0;
}