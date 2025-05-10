#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
#define N 200005

using namespace std;

// https://codeforces.com/contest/1682/problem/B

typedef long long  ll;

int a[N];

void solve(){
    int n; cin >> n;
    for (int i=0;i<n;++i) scanf("%d",a+i);
    int X = ~0;
    for (int i=0;i<n;++i){
        if (a[i] != i) X &=a[i];
    }
    cout << X << endl;
}

int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
} 