#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
#define N 200005

using namespace std;

// https://codeforces.com/contest/1646/problem/C

typedef long long  ll;

void solve(){
    ll n;
    cin >> n;
    vector<ll> fact(15);
    fact[0] = 1;
    for (int i=1;i<15;++i) fact[i] = fact[i-1]*i;
    int mini = 100;
    for (int i=0;i<(1<<15);++i){
        ll sum=0;
        for (int j=0;j<15;++j){
            if (i&(1<<j)) sum += fact[j];
        }
        if (sum <= n) mini = min(mini,__builtin_popcount(i) + __builtin_popcountll(n-sum));
    }
    cout << mini << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}