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
    int k;
    string s, t;
    cin >> k >> s >> t;
    int n = s.size(), m = t.size();
    if(n > m){
        n = t.size(), m = s.size();
        swap(s,t);
    }
    if(abs(n-m) > 1) return false;
    if(n == m){
        int cnt = 0;
        rep(i,n) if(s[i] != t[i]) cnt++;
        if(cnt > 1) return false;
    }else if(m-n == 1){
        reverse(all(t));
        reverse(all(s));
        string tt = "";
        while(s.size()){
            char c = s.back();
            if(c == t.back()){
                s.pop_back();
            }else{
                tt += t.back();
                if(tt.size() > 1) return false;
            }
            t.pop_back();
        }
    }
    return true;
}

int main(){
    if(solve()) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
