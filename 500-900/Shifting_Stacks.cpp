#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1486/problem/A

typedef long long  ll;
 
 
void solve(){
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i=0;i<n;++i) cin >> h[i];
    ll total = 0;
    for (int i=0;i<n;++i){
        total+=h[i];
        total-=i;
        if (total<0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}