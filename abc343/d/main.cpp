// D - Diversity of Scores
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
    int n, t;
    cin >> n >> t;
    vector<ll> num(n,0);
    map<ll,int> mp;
    mp[0] = n;
    rep(i,t){
        int a, b; cin >> a >> b;
        --a;
        mp[num[a]]--;
        if(mp[num[a]] == 0) mp.erase(num[a]);
        num[a] += b;
        mp[num[a]]++;
        cout << mp.size() << el;
    }
    return 0;
}
