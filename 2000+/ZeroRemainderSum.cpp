#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1433/problem/F

typedef long long  ll;
 
int a[75][75];
int dp[75][75][40][75];
//int dp[row][col][num][sum]

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    int limit = m/2;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            scanf("%d",*(a+i)+j);
        }
    }

    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            for (int l=0;l<=limit;++l){
                for (int o=0;o<k;++o) {
                    dp[i][j][l][o] = -1;
                }
            }
        }
    }
    dp[1][1][0][0] = 0;

    for (int row=1;row<=n;++row){
        if (row>1){
            for (int num=0;num<=m/2;++num){
                for (int i=0;i<k;++i){
                    dp[row][1][0][i] = max(dp[row][1][0][i],dp[row-1][m][num][i]);
                    if (m>1 && dp[row-1][m][num][i] != -1)
                        dp[row][1][1][(i+a[row][1])%k] = max(dp[row][1][1][(i+a[row][1])%k],dp[row-1][m][num][i] + a[row][1]);
                }
            }
        } else {
            if(m>1) dp[row][1][1][a[1][1]%k] = a[1][1];
        }

        for (int col=2;col<=m;++col){
            limit = min(m/2,col);
            for (int num=0;num<limit;++num){
                for (int i=0;i<k;++i){
                    dp[row][col][num][i] = max(dp[row][col][num][i],dp[row][col-1][num][i]);
                    if (dp[row][col-1][num][i] != -1)
                       dp[row][col][num+1][(i+a[row][col])%k] = max(dp[row][col][num+1][(i+a[row][col])%k],dp[row][col-1][num][i] + a[row][col]);
                }
                
            }
            for (int i=0;i<k;++i) dp[row][col][limit][i] = max(dp[row][col][limit][i],dp[row][col-1][limit][i]);
        }
    }
    int maxim=0;
    for (int num=0;num<=limit;++num){
        maxim = max(maxim,dp[n][m][num][0]);
    }
    cout << maxim;
    return 0;
}