// B - 3人でカードゲームイージー
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
    string sa, sb, sc;
    cin >> sa >> sb >> sc;
    char sta = 'a';
    int a = 0, b = 0, c = 0;
    while(true){
        if(sta == 'a'){
            if(a == (int)sa.size()){
                cout << "A" << el;
                return 0;
            }else{
                sta = sa[a++];
            }
        }else if(sta == 'b'){
            if(b == (int)sb.size()){
                cout << "B" << el;
                return 0;
            }else{
                sta = sb[b++];
            }
        }else if(sta == 'c'){
            if(c == (int)sc.size()){
                cout << "C" << el;
                return 0;
            }else{
                sta = sc[c++];
            }
        }
    }
    return 0;
}
