#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/gym/306143/problem/F

typedef long long  ll;

#define N 5005
ll dp[N][N]; //how many ways [i islenda in first cluster][j islands in 2nd cluster]

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    for (int i=1;i<N;++i){
        dp[i][1] = i+1;
        dp[1][i] = i+1;
    }
    //dp[a][b] = dp[a-1][b] + dp[a-1][b-1]*b
    for (int i=2;i<N;++i){
        for (int j=2;j<N;++j){
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]*j % MOD) % MOD;
        }
    }
    ll result = dp[a][b] * dp[a][c] % MOD * dp[b][c] % MOD;
    cout << result << endl;
    return 0;
}