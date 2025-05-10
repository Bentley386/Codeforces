#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1481/problem/B

typedef long long  ll;
 
#define N 300005
 
void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> h = vector<int>(n);
    for (int i=0;i<n;++i) cin >> h[i];
    for (int i=0;i<n-1;++i){
        if (h[i] >= h[i+1]) continue;
        else {
            h[i]++;
            k--;
            if (k==0){
                cout << i+1 << endl;
                return;
            }
            i=-1;
        }
    }
    cout << -1 << endl;
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}