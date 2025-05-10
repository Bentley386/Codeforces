#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
#define N 1000006

using namespace std;

// https://codeforces.com/contest/1650/problem/D

typedef long long  ll;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n),d(n);
    for (int i=0;i<n;++i) scanf("%d",&a[i]);
    for (int i=n-1;i>0;--i){
        for (int j=i;j>=0;--j) {
            if (a[j]==i+1){
                d[i] = j+1;
            } 
        }
        if (d[i] == i+1) d[i] = 0;
        rotate(a.begin(), a.begin()+d[i],a.begin()+i+1);
    }
    d[0] = 0;
    for (int x : d) cout << x << " ";
    cout << endl;
}


int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
}