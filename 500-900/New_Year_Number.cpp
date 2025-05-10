#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1475/problem/B

typedef long long  ll;
 
unordered_set<int> possible;
void solve(){
    possible = unordered_set<int>();
    for (int i=1;i<500;++i){
        for (int j=0;j<=i;++j){
            possible.insert(j*2020+(i-j)*2021);
        }
    }
}
 
int main(){
    solve();
    int t;
    cin >> t;
    int n;
    while (t--){
        cin >> n;
        if (possible.count(n)==1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}