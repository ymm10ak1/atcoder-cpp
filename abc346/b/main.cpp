#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int w, b;
    cin >> w >> b;
    string s = "wbwbwwbwbwbw";
    int n = s.size();
    rep(i,n){
        int cw = 0, cb = 0;
        int j = 0;
        while(cw<w || cb<b){
            if(s[(i+j)%n] == 'w') cw++;
            else cb++;
            j++;
        }
        if(cw==w && cb==b){
            cout << "Yes" << el;
            return 0;
        }
    }
    cout << "No" << el;
    return 0;
}
