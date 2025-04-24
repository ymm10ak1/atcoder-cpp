// template {{{
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;
// }}}

struct Card{
    int a, c, idx;
    Card(int a, int c, int idx) : a(a), c(c), idx(idx) {}
};

int main(){
    int n; cin >> n;
    vector<int> a(n), c(n);
    rep(i,n) cin >> a[i] >> c[i];
    vector<Card> ca;
    rep(i,n) ca.emplace_back(a[i],c[i],i+1);
    sort(all(ca), [](const Card& a, const Card& b){
        return tie(a.a, a.c, a.idx) > tie(b.a, b.c, b.idx);
    });
    int ai = ca[0].a, ci = ca[0].c;
    vector<int> ans;
    ans.push_back(ca[0].idx);
    repi(i,1,n){
        if(ai>ca[i].a && ci<ca[i].c) continue;
        ai = ca[i].a; ci = ca[i].c;
        ans.push_back(ca[i].idx);
    }
    sort(all(ans));
    cout << ans.size() << el;
    rep(i,ans.size()) printf("%d%c", ans[i], i==(int)ans.size()-1?'\n':' ');
    return 0;
}
