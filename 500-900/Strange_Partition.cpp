#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1471/problem/A

typedef long long  ll;
 
void solve(){
    int n,x;
    cin >> n >> x;
    ll sum1=0,sum2=0;
    for (int y,i=0;i<n;++i) {
        scanf("%d",&y);
        sum1+=y;
        sum2+=ceil((double)y/x);
 
    }
    sum1 = ceil((double)sum1/x);
    cout << sum1 << " " << sum2 << endl;
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}