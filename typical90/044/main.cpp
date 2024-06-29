// 044 - Shift and Swapping（★3）
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

// NOTE: 解説見ると見かけ上の変化をメモする方法(どのくらいシフトしたか)で、元々の配列のままでクエリを処理できる
// a[(i+shift)%n]のように何回シフトをしているかを管理する
int main(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    deque<int> de;
    rep(i,n){
        cin >> a[i];
        de.push_back(a[i]);
    }
    rep(i,q){
        int t, x, y;
        cin >> t >> x >> y;
        --x; --y;
        if(t == 1){
            swap(de[x], de[y]);
        }else if(t == 2){
            int ba = de[n-1];
            de.pop_back();
            de.push_front(ba);
        }else if(t == 3){
            cout << de[x] << el;
        }
    }
    return 0;
}
