#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1475/problem/A

typedef long long  ll;
 
bool solve(ll n){
    while (n>1){
        if (n%2==1) return true;
        n/=2;
    }
    return false;
}
 
int main(){
    int t;
    cin >> t;
    ll n;
    while (t--){
        cin >> n;
        if (solve(n)) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}