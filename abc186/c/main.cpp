// C - Unlucky 7
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
    int n; cin >> n;
    set<int> st;
    repi(i,1,n+1){
        int num = i;
        while(num){
            if(num%10 == 7){
                st.insert(i);
                break;
            }
            num /= 10;
        }
        num = i;
        while(num){
            if(num%8 == 7){
                st.insert(i);
                break;
            }
            num /= 8;
        }
    }
    cout << n-st.size() << el;
    return 0;
}
