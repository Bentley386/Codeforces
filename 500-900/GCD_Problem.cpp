#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;

// https://codeforces.com/contest/1617/problem/B

typedef long long  ll;

void solve(){
    int n; cin >> n;
    for (int i=2;;++i){
        if (__gcd(i,n-i-1) == 1) {
            cout << i << " " << n-i-1 << " 1\n";
            return;
        }
    }
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}