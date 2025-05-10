#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
#define N 200005

using namespace std;

// https://codeforces.com/contest/1680/problem/A

typedef long long  ll;

void solve(){
    int l1,r1,l2,r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if (max(l1,l2) <= min(r1,r2)){
        cout << max(l1,l2) << endl;
    }
    else {
        cout << l1+l2 << endl;
    }
}

int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
} 