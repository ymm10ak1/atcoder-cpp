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
    vector<pair<char,int>> cnt;
    for(int i=0; i<n;){
        int j = i+1;
        while(j<n && s[i]==s[j]) j++;
        cnt.push_back({s[i],j-i});
        i = j;
    }
    int ans = 0;
    rep(i,cnt.size()){
        if(cnt[i].first == 'O') ans += (cnt[i].second/k);
    }
    cout << ans << el;
    return 0;
}