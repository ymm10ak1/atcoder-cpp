// template {{{
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = (1<<30);
const ll LLINF = (1LL<<60);
// }}}

int main(){
    string s; cin >> s;
    reverse(all(s));
    string t = "";
    int i = 0, ans = 0;
    while(!s.empty()){
        char c = s.back();
        if(i%2){
            if(c == 'o'){
                t += c;
                s.pop_back();
            }else{
                t += 'o';
                ans++;
            }
        }else{
            if(c == 'i'){
                t += c;
                s.pop_back();
            }else{
                t += 'i';
                ans++;
            }
        }
        i++;
    }
    if((int)t.size()%2) ans++;
    cout << ans << el;
    return 0;
}
