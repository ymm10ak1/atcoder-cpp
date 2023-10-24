// D - 2017-like Number
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repi(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i=n-1; i>=s; --i)
#define repli(i, s, n) for(ll i=(s); i<(ll)(n); ++i)
#define repl(i, n) repli(i, 0LL, n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LINF = 1e18;

const int r_max = 100010;
vector<int> eratosthenes(){
    vector<int> isprime(r_max, 1);
    isprime[1] = 0;

    // ふるい
    repi(i, 2, r_max){
        // 合成数はスキップ
        if(isprime[i] == 0) continue;

        // i以外のiの倍数から素数でない数字を0に更新する
        for(int j=i*2; j<r_max; j+=i){
            isprime[j] = 0;
        }
    }
    return isprime;
}

vector<int> check(const vector<int> &e){
    vector<int> isprime(r_max, 0);
    repi(i, 2, r_max){
        int v = (i+1)/2;
        if(e[i]==1 && e[v]==1){
            isprime[i] = 1;
        } 
    }
    return isprime;
}

int main(){
    int q;
    cin >> q;
    vector<int> l(q), r(q);
    rep(i, q) cin >> l[i] >> r[i];
    auto a = check(eratosthenes());
    vector<int> b(r_max+1, 0);
    repi(i, 1, r_max) b[i] = b[i-1]+a[i];
    vector<int> ans;
    rep(i, q){
        ans.push_back(b[r[i]]-b[l[i]-1]);
    }
    for(auto v : ans) cout << v << el;
    return 0;
}