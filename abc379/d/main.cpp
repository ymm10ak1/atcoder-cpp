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
    int q; cin >> q;
    vector<pair<int,int>> qi;
    vector<int> q1,q2;
    int plant = 0;
    rep(i,q){
        int t; cin >> t;
        if(t == 1){
            qi.emplace_back(1,0);
            plant++;
        }else if(t == 2){
            int T; cin >> T;
            qi.emplace_back(2,T);
            q2.push_back(T);
            q1.push_back(plant);
        }else{
            int h; cin >> h;
            qi.emplace_back(3,h);
        }
    }
    vector<ll> s(q2.size()+1,0);
    if(q2.size() > 0){
        reverse(all(q2));
        rep(i,q2.size()) s[i+1] = s[i]+q2[i];
    }
    if(q1.size() > 0){
        int last = q1[q1.size()-1];
        while(q1.size() < s.size()) q1.push_back(last);
        reverse(all(q1));
    }
    map<ll,int> mp;
    if(q1.size() > 0) rep(i,s.size()) mp[s[i]] = q1[i];
    int cnt2 = 0, prev = 0;
    rep(i,qi.size()){
        if(qi[i].first == 2){
            cnt2++;
        }else if(qi[i].first == 3){
            ll key = qi[i].second;
            if((int)s.size()-cnt2-1 >= 0) key += s[s.size()-cnt2-1];
            int idx = lower_bound(all(s),key)-s.begin();
            int ans = 0;
            if(idx < (int)s.size()){
                ans = mp[s[idx]]-prev;
                prev = mp[s[idx]];
            }
            cout << ans << el;
        }
    }
    return 0;
}