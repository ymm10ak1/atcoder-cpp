// B - Cakes and Donuts
#include<bits/stdc++.h>
#define repi(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i=n-1; i>=s; --i)
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    bool flag = false;
    rep(i, n/4+1){
        rep(j, n/7+1){
            if(4*i+7*j == n) flag = true;
        }
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}