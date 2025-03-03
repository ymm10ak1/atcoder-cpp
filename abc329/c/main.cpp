#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n;
    string s;
    cin >> n >> s;
    set<pair<char,int>> st;
    for(int i=0; i<n;){
        int j = i+1;
        st.insert({s[i],j-i});
        while(j<n && s[i]==s[j]){
            j++;
            st.insert({s[i],j-i});
        }
        i = j;
    }
    cout << st.size() << el;
    return 0;
}
