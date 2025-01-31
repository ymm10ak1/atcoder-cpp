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
    int w, h, n;
    cin >> w >> h >> n;
    vector<int> p(n), q(n);
    rep(i,n){
        cin >> p[i] >> q[i];
        p[i] *= -1;
        q[i] *= -1;
    }
    int A; cin >> A;
    vector<int> a(A+1);
    a[0] = 0;
    repi(i,1,A+1){
        cin >> a[i];
        a[i] *= -1;
    }
    int B; cin >> B;
    vector<int> b(B+1);
    b[0] = 0;
    repi(i,1,B+1){
        cin >> b[i];
        b[i] *= -1;
    }
    sort(all(a));
    sort(all(b));
    // NOTE: map<pair<int,int>,int>のほうがわかりやすくて良い
    map<int,map<int,int>> mp;
    rep(i,n){
        int idxa = upper_bound(all(a),p[i])-a.begin();
        int idxb = upper_bound(all(b),q[i])-b.begin();
        mp[a[idxa]][b[idxb]]++;
    }
    int minm = INF, maxm = 0;
    ll cnt = 0;
    for(auto m1 : mp){
        for(auto m2 : m1.second){
            cnt++;
            minm = min(minm, m2.second);
            maxm = max(maxm, m2.second);
        }
    }
    if(cnt < ((ll)A+1)*((ll)B+1)) minm = 0;
    printf("%d %d\n", minm, maxm);
    return 0;
}
