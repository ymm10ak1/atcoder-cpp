// A
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
    int a, b;
    cin >> a >> b;
    int ans = 0;
    repi(x,-200,200){
        if(b-a == x-b) ++ans;
        else if(x-a == b-x) ++ans;
        else if(a-x == b-a) ++ans;
        else if(b-x == a-b) ++ans;
        else if(a-b == x-a) ++ans;
        else if(x-b == a-x) ++ans;
    }
    cout << ans << el;
    return 0;
}
