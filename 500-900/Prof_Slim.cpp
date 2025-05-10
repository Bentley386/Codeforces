#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
#define N 100005

using namespace std;

// https://codeforces.com/contest/1670/problem/A

typedef long long  ll;

int a[N];

void solve(){
    int n; cin >> n;
    int numneg = 0;
    for (int i=0;i<n;++i){
        scanf("%d",a+i);
        if (a[i] < 0) numneg++;
    }
    for (int i=0;i<n;++i){
        if (i<numneg) a[i] = -abs(a[i]);
        else a[i] = abs(a[i]);
    }
    for (int i=1;i<n;++i){
        if (a[i] < a[i-1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
} 