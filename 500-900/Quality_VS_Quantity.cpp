#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
#define N 200005

using namespace std;

// https://codeforces.com/contest/1646/problem/B

typedef long long  ll;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;++i) scanf("%d",&a[i]);
    sort(a.begin(),a.end());
    bool can = false;
    ll sumred=0, sumblue=a[0];
    for (int i=1;i<=n;++i){
        if (2*i+1 > n) break;
        sumblue+=a[i];
        sumred+=a[n-i];
        if (sumred > sumblue) can=true;
    }
    if (can) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}