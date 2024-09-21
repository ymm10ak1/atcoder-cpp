// D - Scope
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

bool solve(){
    string s; cin >> s;
    stack<char> st;
    set<char> stc;
    rep(i,s.size()){
        if(s[i] == '('){
            st.push(s[i]);
        }else if(s[i] == ')'){
            char c = st.top();
            while(c != '('){
                stc.erase(c);
                st.pop();
                c = st.top();
            }
            // '('も削除する
            st.pop();
        }else{
            if(stc.count(s[i])) return false;
            else stc.insert(s[i]);
            st.push(s[i]);
        }
    }
    return true;
}

int main(){
    if(solve()) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
