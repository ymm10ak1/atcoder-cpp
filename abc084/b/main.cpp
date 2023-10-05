// B - Postal Code
#include<bits/stdc++.h>
#define repi(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i=n-1; i>=s; --i)
using namespace std;
using ll = long long;

int main(){
    int a, b;
    string s;
    cin >> a >> b;
    cin >> s;
    bool flag = true;
    rep(i, s.size()){
        if(i != a){
            if(s[i] == '-') flag = false;
        }else{
            if(s[i] != '-') flag = false;
        }
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}