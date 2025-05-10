#include<bits/stdc++.h>
 
using namespace std;

// https://codeforces.com/contest/1635/problem/D

using ll = long long;

constexpr ll INF = 2000000000;
constexpr ll MOD = 1000000007;
constexpr int N = 200005;

ll dp[N]; //dp[i] how many ways if we have i bits left
ll dpTot[N];
int a[N];

void solve(){
    int n, p;
    cin >> n >> p;
    for (int i=0;i<n;++i) scanf("%d",a+i);
    dp[0] = 1;
    dp[1] = 1;
    for (int i=2;i<=p;++i){
        dp[i] = (dp[i-1]+dp[i-2]) % MOD;
    }
    dpTot[0] = 1;
    for (int i=1;i<=p;++i) dpTot[i] = (dpTot[i-1] + dp[i]) % MOD;
    sort(a,a+n);
    set<int> seen;
    ll num = 0;
    for ( int j=0;j<n;++j){
        int x = a[j];
        int numbits = 32-__builtin_clz(x); //num of bits in x
        if (numbits > p) continue;
        int numzeros=0;
        int free = p-numbits;
        bool yes = true;
        for (int i=0;i<numbits;++i){ //if suffix of (i+1) is legal check if prefix is in
            if ((1<<i) & x){
                if (numzeros&1) break;
                numzeros=0;
            } else {
                numzeros++;
            }
            if (!(numzeros&1) && seen.count(x>>(i+1))) {
                yes=false;
                break;
            }
        }
        if (yes){
            num = (num + dpTot[free]) % MOD;
            seen.insert(x);
        }
    }

    cout << num % MOD<< endl;
}

int main(){
    solve();
    return 0;
}