#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;
typedef long long  ll;
 
#define N 100005
 
int c[N],a[N],b[N];
 
void solve(){
    int n;
    cin >> n;
    for (int i=0;i<n;++i) scanf("%d",c+i);
    for (int i=0;i<n;++i) scanf("%d",a+i);
    for (int i=0;i<n;++i) scanf("%d",b+i);
    for (int i=0;i<n;++i){
        if(b[i] < a[i]) swap(a[i],b[i]);
    }
    ll best = b[1]-a[1] + 2;
    ll result = 0;
    for (int i=2;i<n;++i){
        result = max(result,best+c[i-1]-1);
        if (a[i]==b[i]){
            best = 2;
        } else {
            best = best + a[i]-1 + c[i-1]-b[i]+2;
        }
        if (b[i]-a[i]+2 > best) best = b[i]-a[i]+2;
    }
 
    result = max(result,best+c[n-1]-1);
 
    cout << result << endl;
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}