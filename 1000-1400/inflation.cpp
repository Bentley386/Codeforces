#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1476/problem/B

typedef long long  ll;
 
void solve(){
    ll n,k;
    cin >> n >> k;
    ll p0;
    cin >> p0;
    ll total=p0;
    ll changes=0;
    for (ll p,i=1;i<n;++i){
        cin >> p;
        if (p*100>total*k){
            ll change = (p*100-total*k+k-1)/k;
            changes+=change;
            total+=change;
        }
        total+=p;
    }
    cout << changes << endl;
 
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}