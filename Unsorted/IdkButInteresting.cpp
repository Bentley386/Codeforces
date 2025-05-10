#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;
typedef long long  ll;
 
#define N 100005

//problem statement: find out the number of strings of 1s and 0s of length n, such that it has some streak of 5 consecutive
//0s or 1s in it.

ll dp[100][32];

int main(){
    int n;
    cin >> n;
    dp[5][0]=1;
    dp[5][(1<<5)-1]=1;
    for (int i=6;i<=n;++i){
        dp[i][0] = 2LL*dp[i-1][0] % MOD;
        dp[i][(1<<5)-1] = 2LL*dp[i-1][(1<<5)-1] % MOD;
        for (int j=1;j<(1<<5)-1;++j){
            dp[i][j] = (dp[i-1][j>>1] + dp[i-1][(j>>1) + (1<<4)]) % MOD;
        }
    }
    ll result = 0;
    for (int i=0;i<1<<5;++i){
        result+=dp[n][i];
        result %= MOD;
    }
    cout << result;
}