#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1475/problem/C

typedef long long  ll;
 
#define N 205000
 
int va[N],amounta[N];
int vb[N],amountb[N];
void solve(){
    int a,b,k;
    cin >> a >> b >> k;
    ll combs = 0;
    for (int i=0;i<k;++i) {
        scanf("%d",va+i);
        amounta[va[i]]++;
    }
    for (int i=0;i<k;++i) {
        scanf("%d",vb+i);
        amountb[vb[i]]++;
    }
    for (int i=0;i<k;++i){
        combs += k-1-(amounta[va[i]]-1)-(amountb[vb[i]]-1);
    }
 
    for (int i=1;i<=a;++i) amounta[i]=0;
    for (int i=1;i<=b;++i) amountb[i]=0;
 
    cout << combs/2 << endl;
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}