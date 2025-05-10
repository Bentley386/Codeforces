#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1467/problem/A

typedef long long  ll;
 
void solve(){
    int n;
    cin >> n;
    cout << 9;
    if (n>1) cout << 8;
    for(int i=0;i<n-2;++i){
        cout << (9+i)%10;
    }
    cout << "\n";
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}