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

// 考えても分からなかった
// 解説見ると整数xが左から何番目にいるかを表す配列を用意して、右隣(x==nの場合は左隣)の値と交換することで解けるみたい
int main(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i,n) a[i] = i+1;
    rep(i,q){
        int x; cin >> x;
    }
    return 0;
}