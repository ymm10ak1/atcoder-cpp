// B38 - Heights of Grass
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

int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> cnt(n, 1);
    repi(i, 1, s.size()){
        if(s[i] == 'A'){
            if(s[i-1] == 'A') cnt[i] = cnt[i-1]+1;
            else if(s[i-1] == 'B') cnt[i-1] = cnt[i]+1;
        }else if(s[i] == 'B'){
            if(i==s.size()-1) cnt[i] = 2;
            if(s[i-1]=='A') cnt[i] = cnt[i-1]+1;
        }
    }
    rrepi(i, s.size()-1, 0){
        if(s[i]=='B' && s[i+1]=='B') cnt[i] = cnt[i+1]+1;
        if(s[i]=='A' && s[i+1]=='B') cnt[i+1] = max(cnt[i]+1, cnt[i+1]);
    }
    if(s[n-2]=='A') cnt[n-1] = cnt[n-2]+1;
    else if(s[n-2]=='B') cnt[n-1] = 1;
    int sum = 0;
    rep(i, n) sum += cnt[i];
    cout << sum << el;
    return 0;
}