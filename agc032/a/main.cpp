// A - Limited Insertion
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
    vector<int> b(n);
    rep(i,n) cin >> b[i];
    vector<int> ans;
    while(b.size() > 0){
        bool ok = false;
        int blen = b.size();
        rrepi(i,blen+1,1){
            if(b[i-1] == i){
                ok = true;
                ans.push_back(i);
                b.erase(b.begin()+i-1);
                break;
            }
        }
        // i(1<=i<=n)番目にiとなる箇所が見つからない場合は終了
        if(!ok) break;
    }
    if((int)ans.size() == n){
        reverse(all(ans));
        rep(i,ans.size()) cout << ans[i] << el;
    }else{
        cout << -1 << el;
    }
    return 0;
}
