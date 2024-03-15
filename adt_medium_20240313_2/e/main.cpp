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
    string s;
    int k;
    cin >> s >> k;
    sort(all(s));
    int i=1;
    do{
        if(i == k){
            rep(j,s.size()) cout << s[j];
            cout << el;
            return 0;
        }else{
            i++;
        }
    }while(next_permutation(all(s)));
    return 0;
}