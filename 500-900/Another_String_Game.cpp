#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1480/problem/A

typedef long long  ll;
 
 
void solve(){
    string s;
    getline(cin,s);
    bool odd = true;
    for (char &c : s){
        if (c=='\n') break;
        if (odd) {
            if (c=='a') cout << 'b';
            else cout << 'a';
        } else {
            if (c=='z') cout << 'y';
            else cout << 'z';
        }
        odd = !odd;
    }
    cout << "\n";
}
 
int main(){
    int t;
    cin >> t;
    string s;
    getline(cin,s);
    while (t--){
        solve();
    }
    return 0;
}