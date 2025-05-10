#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;

// https://codeforces.com/contest/1591/problem/B

typedef long long  ll;

#define N 200005

int a[N];

void solve(){
    int n;
    cin >> n;
    for (int i=0;i<n;++i) scanf("%d",a+i);
    int maximum=*max_element(a,a+n);
    int result = 0;
    int prev=-1;
    for (int i=n-1;i>=0;--i){
        if (a[i] == maximum) break;
        if (a[i] > prev) {
            prev = a[i];
            result++;
        }
    }
    cout << result << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}