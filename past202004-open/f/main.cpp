// F - タスクの消化
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
    cin >> n;
    vector<vector<int>> a(n);
    rep(i, n){
        int ai, bi;
        cin >> ai >> bi;
        --ai;
        a[ai].push_back(bi);
    }
    priority_queue<int> que;
    int res = 0;
    vector<int> ans;
    for(vector<int> v : a){
        // i日目のタスクを追加していく
        for(int vi : v) que.push(vi);
        if(!que.empty()){
            // i日目までのタスクの中から最大値を足す
            res += que.top();
            ans.push_back(res);
            que.pop();
        }
    }
    for(int v : ans) cout << v << el;
    return 0;
}