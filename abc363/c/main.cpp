// C - Avoid K Palindrome 2
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
    int n, k;
    string s;
    cin >> n >> k >> s;
    sort(all(s));
    int ans = 0;
    do{
        // sの中にk文字の回分が存在するか
        bool ok = true;
        rep(i,n-k+1){
            string t = "";
            rep(j,k) t += s[i+j];
            bool check = false;
            rep(j,k/2){
                if(t[j] != t[k-1-j]) check = true;
            }
            if(!check) ok = false;
        }
        if(ok) ans++;
    }while(next_permutation(all(s)));
    cout << ans << el;
    return 0;
}
