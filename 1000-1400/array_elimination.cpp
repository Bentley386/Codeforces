#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;

// https://codeforces.com/contest/1602/problem/C

typedef long long  ll;

#define N 200005
int a[N];

void solve(){
    int n; cin >> n;
    vector<int> number(30,0);
    bool allzero=true;
    for (int i=0;i<n;++i) {
        scanf("%d",a+i);
        for (int j=0;j<30;++j) {
            if (a[i]&(1<<j)) number[j]++;
        }
        if (a[i]!=0) allzero = false;
    }
    for (int k=1;k<=n;++k){
        bool ok=true;
        for (int j=0;j<30;++j){
            if (allzero) break;
            if (number[j] % k) {
                ok = false;
                break;
            }
        }
        if (ok) cout << k << " ";
    }
    cout << "\n";
}

int main(){
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}