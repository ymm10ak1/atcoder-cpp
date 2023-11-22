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

const char carr[] = {'H','D','C','S'};
const char carr2[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    map<string, int> cnt_mp;
    bool check = true;
    map<char, bool> first, second;
    rep(i, 4) first[carr[i]] = true;
    rep(i, sizeof(carr2)) second[carr2[i]] = true;
    rep(i, n){
        cnt_mp[s[i]]++;
        if(cnt_mp[s[i]] > 1) check = false; 
        if(!first[s[i][0]]) check = false;
        if(!second[s[i][1]]) check = false;
    }
    if(check) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}