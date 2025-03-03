#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n, t;
    cin >> n >> t;
    // 増減するのはある得点の人数なのでsetではなくintでよかった
    map<ll,set<int>> mp;
    vector<ll> score(n);
    rep(i,n) mp[0].insert(i);
    rep(i,t){
        int a, b;
        cin >> a >> b;
        a--;
        mp[score[a]].erase(a);
        if(mp[score[a]].size() == 0) mp.erase(score[a]);
        score[a] += b;
        mp[score[a]].insert(a);
        cout << mp.size() << el;
    }
    return 0;
}
