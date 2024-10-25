// C - Manga
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
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int cnt = 0;
    map<int,int> mp;
    rep(i,n){
        if(a[i] <= n){
            if(mp[a[i]] > 0) cnt++;
            else mp[a[i]]++;
        }else cnt++;
    }
    deque<pair<int,int>> dq;
    vector<bool> used(n);
    for(auto [k,v] : mp){
        dq.emplace_back(k,v);
        used[k] = true;
    }
    int ans = 1;
    while(!dq.empty() || cnt>=0){
        // ans巻が読めない場合、本を2冊使って変更する
        if(!used[ans]){
            if(cnt < 2){
                rep(i,2){
                    if(dq.size()>0){
                        if(dq.back().second > 0){
                            dq.back().second--;
                            cnt++;
                        }
                        if(dq.back().second == 0){
                            used[dq.back().first] = false;
                            dq.pop_back();
                        }
                        if(cnt >= 2) break;
                    }else break;
                }
            }
            // 本が作れなければ終了
            if(cnt >= 2) cnt -= 2;
            else break;
            used[ans] = true;
        }else{
            if(dq.size() > 0) dq.pop_front();
        }
        ans++;
    }
    cout << ans-1 << el;
    return 0;
}
