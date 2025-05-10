#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;

// https://codeforces.com/gym/302977/problem/K

typedef long long  ll;
 
#define N 100005

ll dp[2005][2005]; //[length of seq][last element]
int main(){
    int n,k;
    cin >> n >> k;
    for (int i=1;i<=n;++i){
        dp[1][i] = 1LL;
    }
    for (int i=2;i<=k;++i){ //length
        for (int j=1;j<=n;++j){
            for (int l=j;l<=n;l+=j){
                dp[i][l] = (dp[i][l] + dp[i-1][j]) % MOD;
            }
        }
    }
    ll result=0;
    for (int i=1;i<=n;++i){
        result = (result + dp[k][i]) % MOD;
    }
    cout << result;
}