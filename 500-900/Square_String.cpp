#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1619/problem/A

typedef long long  ll;

void solve(){
    string s;
    getline(cin >> ws, s);
    int n=s.length();
    if (n % 2 == 1) {
        cout << "NO\n";
        return;
    }
    if (s.substr(0,n/2) == s.substr(n/2,n/2)) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}