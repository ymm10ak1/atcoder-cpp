// B
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
    cin >> n >> q;
    int l = 0, r = 1;
    int ans = 0;
    rep(i,q){
        char h;
        int t;
        cin >> h >> t;
        t--;
        if(h == 'L'){
            int left = l, cnt = 0;
            bool ok1 = true;
            while(left != t){
                left = (left+1)%n;
                cnt++;
                if(left == r){
                    ok1 = false;
                    break;
                }
            }
            int minl = INF;
            if(ok1) minl = min(minl, cnt);
            bool ok2 = true;
            left = l, cnt = 0;
            while(left != t){
                left = (left-1)%n;
                if(left < 0) left += n;
                cnt++;
                if(left == r){
                    ok2 = false;
                    break;
                }
            }
            if(ok2) minl = min(minl, cnt);
            ans += minl;
            l = t;
        }else{
            int right = r, cnt = 0;
            bool ok1 = true;
            while(right != t){
                right = (right+1)%n;
                cnt++;
                if(right == l){
                    ok1 = false;
                    break;
                }
            }
            int minr = INF;
            if(ok1) minr = min(minr, cnt);
            right = r, cnt = 0;
            bool ok2 = true;
            while(right != t){
                right = (right-1)%n;
                if(right < 0) right += n;
                cnt++;
                if(right == l){
                    ok2 = false;
                    break;
                }
            }
            if(ok2) minr = min(minr, cnt);
            ans += minr;
            r = t;
        }
    }
    cout << ans << el;
    return 0;
}
