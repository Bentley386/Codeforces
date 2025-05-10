#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
#define N 100000
using namespace std;

// https://codeforces.com/contest/1485/problem/B

typedef long long  ll;
 
int num[N+5]; 
int a[N+5];
 
void solve(){
    int n,q,k;
    cin >> n >> q >> k;
    for (int i=0;i<n;++i){
        scanf("%d",a+i);
    }
    num[0]=0;
    for (int i=1;i<n-1;++i){
        int numbers = a[i+1]-a[i-1]-2; //how many can we put on ith place
        num[i] = num[i-1]+numbers; //how many can we put from start to ith
    }
    int l,r;
    for (int i=0;i<q;++i){
        scanf("%d %d",&l,&r);
        if (l==r) {
            printf("%d\n",k-1);
            continue;
        }
        int result = a[l]-2 + (k-a[r-2]-1);
        if (r-l > 1) result+= num[r-2]-num[l-1];
        printf("%d\n",result);
    }
}
 
int main(){
    solve();
    return 0;
}