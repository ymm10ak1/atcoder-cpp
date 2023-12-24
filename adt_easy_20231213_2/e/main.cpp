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

// 以下はWA解
int n, k;

bool check(const vector<int>& a, const vector<int>& b, int st){
    repi(i, 1, n){
        bool fi = false, se = false;
        if(abs(st-a[i])<=k) fi = true;
        if(abs(st-b[i])<=k) se = true;
        if(fi && se){
            if(abs(st-a[i]) > abs(st-b[i])) st = a[i];
            else st = b[i];
        }else if(fi){
            st = a[i];
        }else if(se){
            st = b[i];
        }else{
            return false;
        }
    }
    return true;
}

int main(){
    cin >> n >> k;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    bool ok1 = check(a, b, a[0]);
    bool ok2 = check(a, b, b[0]);
    if(ok1 || ok2) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}