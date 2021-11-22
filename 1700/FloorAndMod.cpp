#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
#define N 100000
using namespace std;
typedef long long  ll;

void solve(){
    int x,y;
    cin >> x >> y;
    ll num = 0;
    for (int m=1;m*m<=x;++m){ 
        int maxb = min(y,x/m-1); 
        int minb=m+1;
        num += ((minb > maxb) ? 0 : maxb-minb+1);
    }

    cout << num << "\n";
}
 
int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}