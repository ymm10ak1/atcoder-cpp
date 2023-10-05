// B - ss
#include<bits/stdc++.h>
#define repi(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i=n-1; i>=s; --i)
using namespace std;
using ll = long long;

int main(){
    string s;
    cin >> s;
    while(s.size()>2){
        if(s.size()%2 == 1) s = s.substr(0, s.size()-1);
        else s = s.substr(0, s.size()-2);
        // sを前半分と後ろ半分に分ける
        string a = s.substr(0, s.size()/2);
        string b = s.substr(s.size()/2, s.size()/2);
        if(a == b){
            cout << s.size() << endl;
            return 0;
        }
    }
    return 0;
}