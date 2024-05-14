// B64 - Shortest Path with Restoration
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

bool kakutei[100005], hukugen[100005];
int cur[100005];

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    rep(i,m){
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    rep(i,100005) cur[i] = INF;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    // 頂点0を確定済み頂点にする
    cur[0] = 0;
    q.push({cur[0],0});
    // ダイクストラ法
    while(!q.empty()){
        // 未確定頂点の中でcurの値が最も小さい頂点posを求める
        int pos = q.top().second; q.pop();
        if(kakutei[pos]) continue;

        // cur[x]の値を更新
        kakutei[pos] = true;
        for(auto p : g[pos]){
            int nxt = p.first;
            int cost = p.second;
            // 隣接する頂点をnxtとし現時点のcur[nxt]と頂点posからnxtにかかる距離cur[pos]+costを比較して小さい方に更新
            if(cur[nxt] > cur[pos]+cost){
                cur[nxt] = cur[pos]+cost;
                q.push({cur[nxt],nxt});
            }
        }
    }
    // 復元処理
    set<pair<int,int>> st;
    rep(i,n) st.insert({cur[i],i});
    vector<int> ans;
    int now = n-1;
    ans.push_back(now+1);
    hukugen[now] = true;
    while(now > 0){
        int minCost = INF;
        // 隣接している頂点を調べる
        for(auto p : g[now]){
            // すでに訪れた頂点はスキップ
            if(hukugen[p.first]) continue;
            // 頂点nowまでの距離より長い場合スキップ
            int newCost = cur[now]-p.second;
            if(newCost < 0) continue;
            auto it = st.find({newCost, p.first});
            if(it != st.end()){
                if(minCost > newCost){
                    minCost = newCost;
                    now = p.first;
                }
            }
        }
        ans.push_back(now+1);
        // 次の頂点が1ならば終了
        if(now == 0) break;
    }
    rrepi(i,ans.size(),0) printf("%d%c",ans[i],i==0?'\n':' ');
    return 0;
}