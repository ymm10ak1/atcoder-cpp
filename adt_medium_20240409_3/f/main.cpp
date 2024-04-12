// F - Manga
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

bool check[300005];

int main(){
    int n; cin >> n;
    vector<int> a(n);
    sort(all(a));
    rep(i,n){
        cin >> a[i];
        check[a[i]] = true;
    }
    // 1巻目から見ていきその巻がない場合にどう処理するか
    // その巻がないとき、巻数の大きい巻から2冊減らすのをどう実装するか
    int ans = 0;
    cout << ans << el;
    return 0;
}