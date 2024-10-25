// C
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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(k), l(q);
    rep(i,k){
        cin >> a[i];
        a[i]--;
    }
    rep(i,q){
        cin >> l[i];
        l[i]--;
    }
    vector<int> math(n,-1);
    rep(i,k)math[a[i]] = i;
    rep(qi,q){
        int ai = a[l[qi]];
        if(ai == n-1) continue;
        if(math[ai+1] == -1){
            int tmp = math[ai];
            math[ai+1] = tmp;
            math[ai] = -1;
            a[l[qi]] = ai+1;
        }
    }
    rep(i,k) printf("%d%c", a[i]+1, i==k-1?'\n':' ');
    return 0;
}
