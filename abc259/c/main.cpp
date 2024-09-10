// C - XX to XXX
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

vector<pair<char,int>> runLength(string s){
    vector<pair<char,int>> ret;
    for(int i=0; i<(int)s.size();){
        int j = i;
        while(j<(int)s.size() && s[i]==s[j]) ++j;
        ret.push_back({s[i],j-i});
        i = j;
    }
    return ret;
}

int main(){
    string s, t;
    cin >> s >> t;
    vector<pair<char,int>> ns, nt;
    ns = runLength(s);
    nt = runLength(t);
    bool ok = true;
    if(ns.size() == nt.size()){
        rep(i,ns.size()){
            if(ns[i].first != nt[i].first){
                ok = false;
            }else{
                if(ns[i].second==1 && nt[i].second>1) ok = false;
                if(ns[i].second > nt[i].second) ok = false;
            }
        }
    }else{
        ok = false;
    }
    if(ok) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
