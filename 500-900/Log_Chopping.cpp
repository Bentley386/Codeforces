#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
#define N 200005

using namespace std;

// https://codeforces.com/contest/1672/problem/A

typedef long long  ll;

int a[100];
void solve() {
    int n; cin >> n;
    for (int i=0;i<n;++i) scanf("%d", a+i);
    int sum=0;
    for (int i=0;i<n;++i) sum+= a[i]-1;
    if (sum % 2 == 0) {
        cout << "maomao90\n";
    } else {
        cout << "errorgorn\n";
    }
}

int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
} 