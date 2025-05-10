#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1471/problem/C

typedef long long  ll;
 
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> c(m),k(n);
    for (int i=0;i<n;++i) scanf("%d",&k[i]);
    for (int i=0;i<m;++i) scanf("%d",&c[i]);
    sort(k.rbegin(),k.rend());
    int giftcount=0;
    ll cost=0;
    for (int i=0;i<n;++i){
        if (giftcount<m && c[k[i]-1] > c[giftcount]){
            cost += c[giftcount++];
        } else {
            cost += c[k[i]-1];
        }
    }
 
    cout << cost << endl;
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}