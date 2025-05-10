#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;

// https://codeforces.com/contest/1618/problem/A

typedef long long  ll;

void solve(){
    vector<int> b(7);
    for (int i=0;i<7;++i) cin >> b[i];
    cout << b[0] << " " << b[1] << " " << b[6]-b[0]-b[1] << endl;
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}