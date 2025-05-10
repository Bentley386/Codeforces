#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1491/problem/A

typedef long long  ll;
 
#define N 100005
 
int a[100005];
 
void solve(){
    int n,q;
    cin >> n >> q;
    int ones = 0;
    for (int i=0;i<n;++i){
        scanf("%d",a+i);
        if (a[i]==1) ones++;
    }
    for (int i=0;i<q;++i){
        int t;
        cin >> t;
        if (t==1){
            cin >> t;
            if (a[t-1] == 1) ones--;
            else ones++;
            a[t-1] = 1 - a[t-1];
        } else {
            cin >> t;
            if (t<=ones) cout << "1\n";
            else cout << "0\n";
        }
    }
}
 
int main(){
    solve();
    return 0;
}