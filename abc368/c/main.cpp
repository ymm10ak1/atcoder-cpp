// C - Triple Attack
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
    int n; cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    ll t = 1; 
    int num[] = {3, 1, 1};
    rep(i,n){
        // NOTE: 解説みると、最初に(h[i]/5)*3回をtに足してh[i]をh[i]%5にして残ったh[i]を
        // 0以下になるまでt%3の値によって引く値を変えるようなループをすれば少なく書ける
        if(t%3 == 0){
            h[i]-=num[t%3]; t++;
            if(h[i] <= 0) continue;
        }else if(t%3 == 2){
            h[i]-=num[t%3]; t++;
            if(h[i] <= 0) continue;
            h[i]-=num[t%3]; t++;
            if(h[i] <= 0) continue;
        }
        int d = h[i]/5;
        int r = h[i]%5;
        h[i] = r;
        t += 3*d;
        if(r == 0) continue;
        h[i] -= r;
        t += min(3,r);
        // while(h[i] > 0){
        //     t += 1;
        //     if(t%3 == 0) h[i] -= 3;
        //     else h[i]--;
        // }
    }
    cout << t-1 << el;
    return 0;
}
