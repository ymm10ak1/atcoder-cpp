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

int main(){
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<pair<char,int>> vp;
    for(int i=0; i<n;){
        int j = i+1;
        while(j<n && s[i]==s[j]) j++;
        vp.emplace_back(s[i],j-i);
        i = j;
    }
    int cnt1 = 0;
    int prevIdx = 0, idx = 0;
    rep(i,vp.size()){
        if(vp[i].first == '1'){
            cnt1++;
            if(cnt1 == k-1) prevIdx = i;
            if(cnt1 == k) idx = i;
        }
    }
    pair<char,int> tmp = vp[idx];
    vp[idx] = vp[prevIdx+1];
    vp[prevIdx+1] = tmp;
    // 文字列に戻す
    rep(i,vp.size()){
        rep(j,vp[i].second) cout << vp[i].first;
    }
    cout << el;
    return 0;
}
