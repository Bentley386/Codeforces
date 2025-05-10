#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
#define N 1000006

using namespace std;

// https://codeforces.com/contest/1650/problem/A

typedef long long  ll;

void solve(){
    string s;
    char c;
    getline(cin >> ws,s);
    cin >> c;
    bool can = false;
    for (int i=0;i<s.length();++i){
        if (s[i] == c && i%2 == 0) can=true;
    }
    if (can) cout << "YES\n";
    else cout << "NO\n";
}


int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
}