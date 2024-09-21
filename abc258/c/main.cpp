// C - Rotation
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
    int n, q;
    string s;
    cin >> n >> q >> s;
    int pos = 0;
    rep(i,q){
        int t, x; cin >> t >> x;
        if(t == 1){
            pos = (pos+x)%n;
        }else{
            char c = ' ';
            --x;
            if(x < pos){
                c = s[(n-pos+x)%n];
            }else{
                c = s[x-pos];
            }
            cout << c << el;
        }
    }
    return 0;
}
