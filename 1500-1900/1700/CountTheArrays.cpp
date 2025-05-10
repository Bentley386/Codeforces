#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>
#include<cmath>
#include<unordered_set>

#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1312/problem/D

typedef long long  ll;

ll binom(int, int);
ll factorials[200010];
ll inv(ll);
ll pow(ll, int);

int main(){
    int n,m;
    cin >> n >> m;
    if (n==2) {
        cout << 0;
        return 0;
    }
    factorials[0]=1;
    for (int i=1;i<m+1;i++) factorials[i]=factorials[i-1]*i % MOD;

    ll result = binom(m,n-1);
    result = result*(n-2) % MOD;
    ll subresult = 0;
    for (int i=1;i<n-1;i++){
        int maks = max(i,n-i-1);
        subresult = (subresult + binom(n-3,maks-1)) % MOD;
    }
    cout << result*subresult % MOD;
    return 0;
}

ll binom(int n, int k){
    if (n==0 || k==0) return 1ll;
    ll inverse = inv(factorials[k]*factorials[n-k] % MOD);
    return factorials[n]*inverse % MOD;
}

ll inv(ll x){
    return pow(x,MOD-2);
}

ll pow(ll x, int n){
    if (n==0) return 1ll;
    ll p = pow(x, n/2);
    p = (p*p) % MOD;
    return (n%2==0) ? p : x*p % MOD;
}