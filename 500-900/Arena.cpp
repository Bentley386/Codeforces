#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1487/problem/A

typedef long long  ll;
 
 
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;++i) cin >> a[i];
    sort(a.begin(),a.end());
    int lowest = a[0];
    int i=1;
    for (;i<n;++i){
        if (a[i] == lowest) continue;
        break;
    }
    cout << n - i << "\n";
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}