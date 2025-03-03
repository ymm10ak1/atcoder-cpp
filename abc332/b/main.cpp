#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int k, g, m;
    cin >> k >> g >> m;
    int ansg = 0, ansm = 0;
    rep(i,k){
        if(ansg == g){
            ansg = 0;
        }else if(ansm == 0){
            ansm = m;
        }else{
            while(1){
                if(ansg==g || ansm==0) break;
                ansm--;
                ansg++;
            }
        }
    }
    printf("%d %d\n", ansg, ansm);
    return 0;
}
