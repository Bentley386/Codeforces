#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1646/problem/A

typedef long long  ll;

void solve(){
    ll n,s;
    cin >> n >> s;
    ll res = n*n;
    cout << s/res << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}