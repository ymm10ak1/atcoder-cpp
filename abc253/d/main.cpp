// D - FizzBuzz Sum Hard
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

ll sum(ll a){
    ll ret = 0;
    if(a%2 == 0) ret = a/2*(a+1);
    else if((a+1)%2 == 0) ret = (a+1)/2*a;
    return ret;
}

ll gcd(ll x, ll y){
    if(y == 0) return x;
    else return gcd(y,x%y);
}

ll lcm(ll x, ll y){
    return x*y/gcd(x,y);
}

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    // nの総和
    ll nSum = sum(n);
    // aの倍数の総和
    ll aNum = n/a;
    ll aSum = a*sum(aNum);
    // bの倍数の総和
    ll bNum = n/b;
    ll bSum = b*sum(bNum);
    // aとbの最小公倍数の総和
    ll ab = lcm(a,b);
    ll abNum = n/ab;
    ll abSum = ab*sum(abNum);
    ll ans = nSum-aSum-bSum+abSum;
    cout << ans << el;
    return 0;
}
