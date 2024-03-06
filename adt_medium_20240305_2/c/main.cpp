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

const vector<string> atco = {"ABC", "ARC", "AGC", "AHC"};

int main(){
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    vector<bool> cnt(4);
    rep(i,atco.size()){
        if(atco[i]==s1 || atco[i]==s2 || atco[i]==s3) cnt[i] = true;
    }
    rep(i,atco.size()){
        if(!cnt[i]) cout << atco[i] << el;
    }
    return 0;
}