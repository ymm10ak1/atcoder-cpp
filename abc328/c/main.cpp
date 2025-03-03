#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n, q;
    string s;
    cin >> n >> q >> s; 
    vector<int> cnt(n);
    rep(i,n){
        if(i > 0){
            cnt[i] += cnt[i-1];
            if(s[i] == s[i-1]) cnt[i]++;
        }
    }
    rep(i,q){
        int l, r;
        cin >> l >> r;
        r--; l--;
        cout << cnt[r]-cnt[l] << el;
    }
    return 0;
}
