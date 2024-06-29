// A - Kenken Race
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

bool check(const vector<int>& sha){
    rep(i,sha.size()-1){
        if(sha[i+1]-sha[i]-1 == 0) return false;
    }
    return true;
}

int main(){
    int n, a, b, c, d;
    string s;
    cin >> n >> a >> b >> c >> d >> s;
    --a; --b; --c; --d;
    // ##のような2マス以上連続して岩があるマスがないか調べる
    vector<int> sha;
    if(b<c && c<d){
        repi(i,a,d+1) if(s[i] == '#') sha.push_back(i);
        if(check(sha)) cout << "Yes" << el;
        else cout << "No" << el;
    }else if(c<b && b<d){
        repi(i,a,c+1) if(s[i] == '#') sha.push_back(i);
        if(!check(sha)){
            cout << "No" << el;
            return 0;
        }
        sha.clear();
        repi(i,b,d+1) if(s[i] == '#') sha.push_back(i);
        if(check(sha)) cout << "Yes" << el;
        else cout << "No" << el;
    }else if(b<d && d<c){
        repi(i,a,c+1) if(s[i] == '#') sha.push_back(i);
        if(!check(sha)){
            cout << "No" << el;
            return 0;
        }
        // #と#の間に何も置かれてないマスが3つ以上なければNo
        vector<int> sha2;
        repi(i,b-2,d+3) if(s[i] == '#') sha2.push_back(i);
        bool ok = false;
        rep(i,sha2.size()-1) if(sha2[i+1]-sha2[i]-1 > 2) ok = true;
        if(ok) cout << "Yes" << el;
        else cout << "No" << el;
    }
    return 0;
}
