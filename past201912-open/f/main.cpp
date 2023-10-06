// F - DoubleCamelCase Sort
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

int main(){
    string s;
    cin >> s;
    vector<string> ss;
    // 文字列の大文字と小文字を無視したソートの方法が分からなかったため解説見た
    for(int i=0; i<s.size();){
        // 各単語最初の文字は大文字であるから+1する
        int j=i+1;
        while(j<s.size() && ('a'<=s[j] && s[j]<='z')){
            ++j;
        }
        // ソートするために文字列の1番目と最後を小文字に変換
        string word = s.substr(i, j-i+1);
        word[0] = tolower(word[0]);
        word.back() = tolower(word.back());
        ss.push_back(word);
        i = j+1;
    }
    sort(all(ss));
    // 出力するときは文字列の1番目と最後を大文字に変換
    for(string t : ss){
        t[0] = toupper(t[0]);
        t.back() = toupper(t.back());
        cout << t;
    } 
    cout << el;
    return 0;
}