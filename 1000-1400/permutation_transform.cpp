#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1490/problem/D

typedef long long  ll;
 
int d[105];
int a[105];
 
void recursion(int l, int r, int depth){
    if (r-1<l) return;
    int maxind = l;
    int maxel = a[l];
    for (int i=l+1;i<r;++i){
        if (a[i]>maxel){
            maxind = i;
            maxel=a[i];
        }
    }
    d[maxind] = depth;
    recursion(l,maxind,depth+1);
    recursion(maxind+1,r,depth+1);
}
 
void solve(){
    int n;
    cin >> n;
    for (int i=0;i<n;++i) cin >> a[i];
    recursion(0,n,0);
    for (int i=0;i<n;++i){
        cout << d[i] << " ";
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