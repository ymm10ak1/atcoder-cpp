// E
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
    string s, t;
    cin >> s >> t;
    map<char,int> mps, mpt;
    rep(i,s.size()) mps[s[i]]++;
    rep(i,t.size()) mpt[t[i]]++;
    string atcoder = "atcoder";
    string ns = "";
    rep(i,s.size()){
        if(s[i]=='@'){
            ns += '@';
            continue;
        }
        if(mpt[s[i]] > 0){
            mpt[s[i]]--;
            if(mpt[s[i]] == 0) mpt.erase(s[i]);
        }else{
            bool flag = false;
            rep(j,atcoder.size()){
                if(s[i]==atcoder[j] && mpt['@']>0){
                    mpt['@']--;
                    if(mpt['@'] == 0) mpt.erase('@');
                    flag = true;
                    break;
                }
            }
            if(!flag){
                cout << "No" << el;
                return 0;
            }
        }
    }
    atcoder += '@';
    rep(i,ns.size()){
        if(ns[i] == '@'){
            bool flag = false;
            rep(j,atcoder.size()){
                if(mpt[atcoder[j]] > 0){
                    mpt[atcoder[j]]--;
                    if(mpt[atcoder[j]] == 0) mpt.erase(atcoder[j]);
                    flag = true;
                    break;
                }
            }
            if(!flag){
                cout << "No" << el;
                return 0;
            }
        }
    }
    cout << "Yes" << el;
    return 0;
}
