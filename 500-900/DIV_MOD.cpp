#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
#define N 1000006

using namespace std;

// https://codeforces.com/contest/1650/problem/B

typedef long long  ll;

void solve(){
    int l,r,a;
    scanf("%d %d %d",&l,&r,&a);
    int max1 = r/a + r%a;
    l = max(l,r-r%a-1);
    int max2 = l/a + l%a;
    printf("%d\n",max(max1,max2));
}


int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
}