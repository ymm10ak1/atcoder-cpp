#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
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
    cin >> n >> s >> q;
    int upper = 0, lower = 0;
    vector<int> last(n);
    int up_or_low = 0;
    rep(qi,q){
        int t, x;
        char c;
        cin >> t >> x >> c;
        if(t == 1){
            s[x-1] = c;
            last[x-1] = qi;
        }else if(t == 2){
            lower = qi;
            up_or_low = 1;
        }else{
            upper = qi;
            up_or_low = 2;
        }
    }
    int check = upper;
    if(upper < lower) check = lower;
    rep(i,n){
        if(last[i] <= check){
            if(up_or_low == 2) s[i] = toupper(s[i]);
            else if(up_or_low == 1) s[i] = tolower(s[i]);
        }
    }
    cout << s << el;
    return 0;
}
