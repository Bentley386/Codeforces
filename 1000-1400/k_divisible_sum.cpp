#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1476/problem/A

typedef long long  ll;
 
void solve(){
    ll n,k;
    cin >> n >> k;
    if (n>k){
        if (n%k==0) k=n;
        else k = (n/k+1)*k;
    }
    if (k%n==0) cout << k/n;
    else cout << k/n+1;
    cout << endl;
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}