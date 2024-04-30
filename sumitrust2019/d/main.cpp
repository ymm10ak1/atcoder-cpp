// D - Lucky PIN
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
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    // 000~999の1000通り試す
    rep(i,1000){
        string si = to_string(i);
        // 3文字未満ならば3文字になるまで"0"を左詰め
        while(si.size()<3) si = "0"+si;
        // 何桁目を見ているか
        int d = 0;
        rep(j,s.size()){
            // 今見ているsの桁の数とsiの桁の数が同じならばsiの次の桁を見るようにする
            if(s[j] == si[d]) ++d;
            // もし3桁すべてを見ることができたなら、そのiはsから設定できる暗証番号なので答えに1加えてループを抜ける
            if(d == 3){
                ++ans;
                break;
            }
        }
    }
    cout << ans << el;
    return 0;
}