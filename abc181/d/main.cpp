// D - Hachi
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

bool solve(const string& s){
    if(s.size() == 1){
        if((s[0]-'0')%8 == 0) return true; 
    }else if(s.size() == 2){
        string t = ""+s[1]+s[0];
        int num1 = (s[0]-'0')*10+(s[1]-'0');
        int num2 = (s[1]-'0')*10+(s[0]-'0');
        if(num1%8==0 || num2%8==0) return true;
    }else{
        map<int,int> mp;
        rep(i,s.size()) mp[s[i]-'0']++;
        repi(i,1,10){
            repi(j,1,10){
                repi(k,1,10){
                    int n1 = mp[i], n2 = mp[j], n3 = mp[k];
                    if(n1==0 || n2==0 || n3==0) continue;
                    if(i==j && j==k && k==i && n1<3) continue;
                    if(i==j && n1<2) continue;
                    if(j==k && n2<2) continue;
                    if(k==i && n3<2) continue;
                    if((i*100+j*10+k)%8 == 0) return true;
                }
            }
        }
    }
    return false;
}

int main(){
    string s; cin >> s;
    if(solve(s)) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
