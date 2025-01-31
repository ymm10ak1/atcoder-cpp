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

bool solve(){
    string s, t;
    cin >> s >> t;
    map<char,int> mp;
    rep(i,t.size()) mp[t[i]]++;
    string ns = "";
    rep(i,s.size()){
        if(s[i] == '@'){
            ns += '@';
            continue;
        }
        if(mp[s[i]] > 0) mp[s[i]]--;
        else ns += s[i];
    }
    if(ns.size() == 0) return true;

    // nsにatcoder@以外が含まれていたらfalse
    string a = "atcoder@";
    rep(i,ns.size()){
        bool check = false;
        rep(j,8) if(ns[i] == a[j]) check = true;
        if(!check) return false;
    }

    sort(rall(ns));
    rep(i,ns.size()){
        bool check = false;
        if(ns[i] != '@'){
            // nsの中の"atcoder"をTの@に使う
            rep(j,7){
                if(mp['@'] > 0){
                    mp['@']--;
                    check = true;
                    break;
                }
            }
        }else{
            // nsの@をTの"atcoder@"に使う
            rep(j,8){
                if(mp[a[j]] > 0){
                    mp[a[j]]--;
                    check = true;
                    break;
                }
            }
        }
        if(!check) return false;
    }
    return true;
}

int main(){
    if(solve()) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
