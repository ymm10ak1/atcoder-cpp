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

bool desc_asc(pair<int, int>& left, pair<int, int>& right){
    if(left.first == right.first){
        return left.second < right.second;
    }else{
        return right.first < left.first;
    }
}

int main(){
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<pair<int, int>> a(n), b(n), c(n);
    rep(i, n){
        cin >> a[i].first;
        a[i].second = i;
    }
    rep(i, n){
        cin >> b[i].first;
        b[i].second = i;
    }
    rep(i, n){
        c[i].first = a[i].first+b[i].first;
        c[i].second = i;
    }
    vector<bool> suc(n, false);
    sort(all(a), desc_asc);
    sort(all(b), desc_asc);
    sort(all(c), desc_asc);
    rep(i, x){
        suc[a[i].second] = true;
    }
    int cnt_y = 0;
    rep(i, n){
        if(cnt_y == y) break;
        if(!suc[b[i].second]){
            suc[b[i].second] = true;
            cnt_y++;
        }
    }
    int cnt_z = 0;
    rep(i, n){
        if(cnt_z == z) break;
        if(!suc[c[i].second]){
            suc[c[i].second] = true;
            cnt_z++;
        }
    }
    rep(i, n){
        if(suc[i]) cout << i+1 << el;
    }
    return 0;
}