// D - Loong and Takahashi
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

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void printArray(const vector<vector<int>>& a, int n){
    repi(i,1,n+1)repi(j,1,n+1){
        if(a[i][j] == INF) cout << "T";
        else cout << a[i][j];
        if(j<n) cout << " ";
        else cout << el;
    }
}

int main(){
    int n; cin >> n;
    vector<vector<int>> a(n+2,vector<int>(n+2,-1));
    rep(i,n+2) a[i][0] = 0, a[i][n+1] = 0;
    rep(i,n+2) a[0][i] = 0, a[n+1][i] = 0;
    int i = 1, j = 1, k = 0;
    int num = 1;
    while((i>=0 && i<=n+1) && (j>=0 && j<=n+1)){
        if(i==(n+1)/2 && j==(n+1)/2){
            a[i][j] = INF;
            printArray(a,n);
            return 0;
        }
        // 方向転換
        if(a[i][j] != -1){
            i -= dx[k];
            j -= dy[k];
            k = (k+1)%4;
        }else{
            a[i][j] = num++;
        }
        i += dx[k];
        j += dy[k];
    }
    return 0;
}
