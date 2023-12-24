// B14 - Another Subset Sum
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
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int n1 = n/2, n2 = n-n/2;
    vector<int> a1, a2;
    rep(i, n){
        if(i < n1) a1.push_back(a[i]);
        else a2.push_back(a[i]);
    }
    vector<ll> p, q;
    // NOTE: このbit全探索の部分を関数化すれば2つ同じ処理を書かずにすむので少しすっきりする
    rep(bit, (1<<n1)){
        ll v = 0;
        rep(i, n1){
            if(bit&(1<<i)) v += a1[i];
        }
        p.push_back(v);
    }
    rep(bit, (1<<n2)){
        ll v = 0;
        rep(i, n2){
            if(bit&(1<<i)) v += a2[i];
        }
        q.push_back(v);
    }
    sort(all(q));
    rep(i, p.size()){
        int q_idx = lower_bound(all(q), k-p[i])-q.begin();
        if(q[q_idx] == k-p[i]){
            cout << "Yes" << el;
            return 0;
        }
    }
    cout << "No" << el;
    return 0;
}