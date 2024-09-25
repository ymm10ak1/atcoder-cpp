// C
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
    set<int> A, B, C;
    rep(i,n){
        if(s[i] == 'A') A.insert(i);
        if(s[i] == 'B') B.insert(i);
        if(s[i] == 'C') C.insert(i);
    }
    int cnt = 0;
    rep(i,n-2) if(A.count(i) && B.count(i+1) && C.count(i+2)) cnt++;
    rep(i,q){
        int x;
        char c;
        cin >> x >> c;
        --x;
        if(A.count(x)){
            if(A.count(x) && B.count(x+1) && C.count(x+2)) cnt--;
            A.erase(x);
        }
        if(B.count(x)){
            if(A.count(x-1) && B.count(x) && C.count(x+1)) cnt--;
            B.erase(x);
        }
        if(C.count(x)){
            if(A.count(x-2) && B.count(x-1) && C.count(x)) cnt--;
            C.erase(x);
        }
        s[x] = c;
        if(c == 'A'){
            A.insert(x);
            if(A.count(x) && B.count(x+1) && C.count(x+2)) cnt++;
        }
        if(c == 'B'){
            B.insert(x);
            if(A.count(x-1) && B.count(x) && C.count(x+1)) cnt++;
        }
        if(c == 'C'){
            C.insert(x);
            if(A.count(x-2) && B.count(x-1) && C.count(x)) cnt++;
        }
        cout << cnt << el;
    }
    return 0;
}
