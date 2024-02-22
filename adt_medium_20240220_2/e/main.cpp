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

int main(){
    int n; cin >> n;
    vector<bool> cnt(2*n+2, false);
    bool takahashi = true;
    while(true){
        repi(i,1,cnt.size()){
            if(!cnt[i]){
                cout << i << endl;
                cnt[i] = true;
                break;
            }
        }
        int aoki; cin >> aoki;
        if(aoki == 0) break;
        cnt[aoki] = true;
    }
    return 0;
}