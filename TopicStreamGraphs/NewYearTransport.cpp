#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/gym/317667/problem/A

typedef long long  ll;

#define N 1000

int main(){
    int n,t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i=1;i<n;++i){
        scanf("%d",&a[i]);
    }
    bool found = false;
    for (int i=1;;){
        if (i==t) found = true;
        if (i==n) break;
        i = (i+a[i]);
    }
    if (found) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}