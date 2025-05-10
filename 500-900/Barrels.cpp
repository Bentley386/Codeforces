#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1430/problem/B

typedef long long  ll;
 
 
int main(){
    int t,n,k;
    cin >> t;
    while (t--){
        cin >> n >> k;
        vector<ll> a(n);
        for (int i=0;i<n;++i) scanf("%d",&a[i]);
        sort(a.begin(),a.end());
        ll difference1=a[n-1];
        for (int i=0;i<k;++i){
            difference1+=a[n-2-i];
        }
        cout << difference1 << "\n";
    }
    return 0;
}