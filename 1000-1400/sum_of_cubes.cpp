#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1490/problem/C

typedef long long  ll;
 
set<ll> cubes;
 
void solve(){
    ll x;
    cin >> x;
    for (ll i : cubes){
        if (cubes.count(x-i)>0){
            cout << "YES\n";
            return;
        }
        if (i>=x/2){
            cout << "NO\n";
            return;
        }
    }
}
 
int main(){
    for (ll i=1;;++i){
        ll temp = i*i*i;
        if (temp > 1e12) break;
        cubes.insert(temp);
    }
 
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}