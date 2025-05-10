#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1496/problem/A

typedef long long  ll;
 
#define N 100005

 
void solve(){
    int n,k;
    cin >> n >> k;
    string s;
    getline(cin >> ws,s);
    for (int i=0;i<k;++i){
        if (s[i]!=s[n-1-i]) {
            cout << "NO\n";
            return;
        }
    }
    if (2*k==n) {
        cout << "NO\n";
        return;
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