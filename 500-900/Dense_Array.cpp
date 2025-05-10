#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1490/problem/A

typedef long long  ll;
 
 
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;++i) cin >> a[i];
    int numbers=0;
    for (int i=0;i<n-1;++i){
        int bigger = max(a[i],a[i+1]);
        int smaller = min(a[i],a[i+1]);
        while (bigger > 2*smaller){
            if (bigger%2 == 0) bigger/=2;
            else bigger = (bigger+1)/2;
            numbers++;
        }
    }
    cout << numbers << "\n";
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}