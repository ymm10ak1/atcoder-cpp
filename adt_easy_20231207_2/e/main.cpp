// 
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
    int n, m, h, k;
    string s;
    cin >> n >> m >> h >> k >> s;
    map<pair<int, int>, int> mp;
    rep(i, m){
        int xi, yi;
        cin >> xi >> yi;
        mp[{xi, yi}] = 1;
    }
    pair<int, int> st = {0, 0};
    rep(i, s.size()){
        // 体力消費
        h--;
        // 移動
        if(s[i] == 'R') st.first++;
        else if(s[i] == 'L') st.first--;
        else if(s[i] == 'U') st.second++;
        else if(s[i] == 'D') st.second--;
        // 体力が負の値ならば終了
        if(h < 0){
            cout << "No" << el;
            return 0;
        }
        // 移動後にアイテム使えるか
        if(mp[st]==1 && h<k){
            h = k;
            mp[st] = 0;
        }
    }
    cout << "Yes" << el;
    return 0;
}