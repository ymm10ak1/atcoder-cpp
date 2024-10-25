// E
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

const int dx[] = {-2,-2,-1,-1,1,1,2,2};
const int dy[] = {-1,1,-2,2,-2,2,-1,1};

int main(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    set<pair<int,int>> st;
    rep(i,8){
        int nx1 = x1+dx[i], ny1 = y1+dy[i];
        if(st.count({nx1,ny1}) == 1){
            cout << "Yes" << el;
            return 0;
        }
        st.insert({nx1,ny1});
        int nx2 = x2+dx[i], ny2 = y2+dy[i];
        if(st.count({nx2,ny2}) == 1){
            cout << "Yes" << el;
            return 0;
        }
        st.insert({nx2,ny2});
    }
    cout << "No" << el;
    return 0;
}
