// A45 - Card Elimination
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
    char c;
    cin >> n >> c;
    vector<char> a(n);
    map<char, int> mp;
    rep(i,n){
        cin >> a[i];
        ++mp[a[i]];
    }
    // NOTE: 解説では、各カードの色を整数で表してそれらの合計を3で割った余りで色を決めている
    // そうすることで以下の実装はもっと簡潔になる
    char b_arr[] = {'W','B','R'};
    char r_arr[] = {'W','R','B'};
    int w_cnt = 0, b_cnt = 0, r_cnt = 0;
    for(auto p : mp){
        int r = p.second%3;
        if(p.first == 'B'){
            if(b_arr[r] == 'W') ++w_cnt;
            else if(b_arr[r] == 'B') ++b_cnt;
            else if(b_arr[r] == 'R') ++r_cnt;
        }else if(p.first == 'R'){
            if(r_arr[r] == 'W') ++w_cnt;
            else if(r_arr[r] == 'B') ++b_cnt;
            else if(r_arr[r] == 'R') ++r_cnt;
        }else if(p.first == 'W'){
            ++w_cnt;
        }
    }
    char res = 'W';
    if(r_cnt == 1) res = 'R';
    else if(b_cnt == 1) res = 'B';
    else if(r_cnt == 2) res = 'B';
    else if(b_cnt == 2) res = 'R';
    if(r_cnt==1 && b_cnt==1) res = 'W';
    if(res == c) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}