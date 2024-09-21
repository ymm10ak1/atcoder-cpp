// D - All Assign Point Add
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
    int n, q;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    cin >> q;
    vector<int> before(n);
    vector<ll> base;
    rep(i,q){
        int t;
        cin >> t;
        int len = base.size();
        if(t == 1){
            int x; cin >> x;
            base.push_back(x);
        }else if(t == 2){
            int iq, x;
            cin >> iq >> x;
            --iq;
            if(before[iq] != len){
                a[iq] = base.back()+x;
                before[iq] = len;
            }else{
                a[iq] += x;
            }
        }else{
            int iq; cin >> iq;
            --iq;
            if(before[iq] != len){
                a[iq] = base.back();
                before[iq] = len;
            }
            cout << a[iq] << el;
        }
    }
    return 0;
}
