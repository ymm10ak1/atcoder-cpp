// D - String Formation
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
    int q;
    string s;
    cin >> s >> q;
    deque<char> de;
    rep(i,s.size()) de.push_back(s[i]);
    bool fro = true;
    rep(i,q){
        int t; cin >> t;
        if(t == 1){
            fro = !fro;
        }else if(t == 2){
            int f;
            char c;
            cin >> f >> c;
            if(f == 1){
                if(fro) de.push_front(c);
                else de.push_back(c);
            }else if(f == 2){
                if(fro) de.push_back(c);
                else de.push_front(c);
            }
        }
    }
    if(fro){
        rep(i,de.size()){
            if(i < (int)de.size()-1) cout << de[i];
            else cout << de[i] << el;
        }
    }else{
        rrepi(i,de.size(),0){
            if(i == 0) cout << de[i] << el;
            else cout << de[i];
        }
    }
    return 0;
}
