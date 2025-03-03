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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    vector<pair<int,char>> c;
    rep(i,n) c.emplace_back(a[i],'a');
    rep(i,m) c.emplace_back(b[i],'b');
    sort(all(c));
    rep(i,c.size()-1){
        if(c[i].second=='a' && c[i+1].second=='a'){
            cout << "Yes" << el;
            return 0;
        }
    }
    cout << "No" << el;
    return 0;
}
