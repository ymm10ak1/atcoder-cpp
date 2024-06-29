// A - Diverse Word
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
    char c = 'a';
    set<char> st;
    string ans = "";
    if((int)s.size() < 26){
        rep(i,s.size()) st.insert(s[i]);
        rep(i,26){
            c = 'a'+i;
            if(st.find(c) == st.end()){
                ans = s+c;
                cout << ans << el;
                return 0;
            }
        }
    }else{
        int idx = -1;
        rrepi(i,s.size(),1){
            st.insert(s[i]);
            if(s[i] > s[i-1]){
                idx = i;
                break;
            }
        }
        if(idx > -1){
            ans = s.substr(0,idx-1);
            for(auto c : st){
                if(s[idx-1] < c){
                    ans += c;
                    break;
                }
            }
            cout << ans << el;
        }else{
            cout << -1 << el;
        }
    }
    return 0;
}
