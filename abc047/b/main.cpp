// B - すぬけ君の塗り絵2イージー
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
    int w, h, n;
    cin >> w >> h >> n;
    // trueが黒色、falseが白色
    vector<bool> tate(h+1,false), yoko(w+1,false);
    rep(i,n){
        int x, y, a;
        cin >> x >> y >> a;
        if(a == 1){
            rep(j,x) yoko[j] = true;
        }else if(a == 2){
            repi(j,x+1,w+1) yoko[j] = true;
        }else if(a == 3){
            rep(j,y) tate[j] = true;
        }else if(a == 4){
            repi(j,y+1,h+1) tate[j] = true;
        }
    }
    int x1 = 0, x2 = w;
    int y1 = 0, y2 = h;
    while(x1<=w && yoko[x1]) x1++;
    while(x2>=0 && yoko[x2]) x2--;
    while(y1<=h && tate[y1]) y1++;
    while(y1>=0 && tate[y2]) y2--;
    if((x1==w+1 && x2==-1) || (y1==h+1 && y2==-1)) cout << 0 << el;
    else cout << (x2-x1)*(y2-y1) << el;
    return 0;
}
