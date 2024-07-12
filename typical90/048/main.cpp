// 048 - I will not drop out（★3）
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

// NOTE: まだ解いてない
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    priority_queue<pair<int, int>> q;
    rep(i,n) q.push({a[i], i});
    ll ans = 0;
    // TODO: AとBのどちらが得点が高いのか選ぶ方法をどう実装するか
    // 下記は正しい解法ではない
    while(k > 0){
        pair<int, int> now = q.top(); q.pop();
        int bi = now.second;
        ans += b[bi];
        k--;
        // 今の問題の得点a-bを用意
        int d = now.first-b[bi];
        if(k>=2 && q.size()>0){
            pair<int, int> nxt = q.top();
            // 今見ている問題の得点a-bが次の問題の得点aより高いなら今の問題を解く
            if(d >= nxt.first){
                ans += d;
            }else{
                ans += nxt.first;
                q.pop();
            }
            k--;
        }else if(k>=2 && q.size()==0){
            ans += d;
            k--;
        }
    }
    cout << ans << el;
    return 0;
}
