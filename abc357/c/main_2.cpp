#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n; cin >> n;
    int m = 1;
    rep(i,n) m *= 3;
    vector<string> s(m,string(m,'#'));
    for(int i=1; i<m; i*=3){
        for(int j=i; j<m; j+=i*3){
            for(int k=i; k<m; k+=i*3){
                for(int a=j; a<j+i; a++){
                    for(int b=k; b<k+i; b++){
                        s[a][b] = '.';
                    }
                }
            }
        }
    }
    rep(i,m) cout << s[i] << el;
    return 0;
}
