#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;
typedef long long  ll;

int a[20][10005];
int combos[20][20]; //maximal k acceptable for 2 row combos
int combosedge[20][20]; //same but with rows on top/bottom
int dp[1<<16][20][20]; //[mask][top][bottom]
int main(){
    int n,m;
    cin >> n >> m;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j) scanf("%d",&a[i][j]);
    }

    if (n==1){
        int answer=INF;
        for (int i=0;i<m-1;++i) answer = min(answer,abs(a[0][i]-a[0][i+1]));
        cout << answer << endl;
        return 0;
    }

    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            if (i==j) continue;
            int mini = INF;
            for (int k=0;k<m;++k){
                mini = min(mini,abs(a[i][k]-a[j][k]));
            }
            combos[i][j] = mini;
        }
    }

    for (int i=0;i<n;++i){ //this one on top
        for (int j=0;j<n;++j){ //this one on bottom
            if (i==j) continue;
            int mini = INF;
            for (int k=0;k<m-1;++k){
                mini = min(mini,abs(a[j][k]-a[i][k+1]));
            }
            combosedge[i][j] = mini;
        }
    }

    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            if (i==j) continue;
            dp[1<<i | 1<<j][i][j] = combos[i][j];
        }
    }

    for (int taken=0;taken<(1<<n)-1;++taken){
        if(__builtin_popcount(taken)<2) continue;
        for (int i=0;i<n;++i){ //top
            if ((taken & 1<<i) == 0) continue;
            for (int j=0;j<n;++j) { //bottom
                if (i==j || (taken & 1<<j) == 0) continue;
                for (int k=0;k<n;++k) { //new
                    if ((taken & 1<<k) != 0) continue;
                    dp[taken | 1<<k][k][j] = max(dp[taken | 1<<k][k][j],min(dp[taken][i][j],combos[k][i]));
                    dp[taken | 1<<k][i][k] = max(dp[taken | 1<<k][i][k],min(dp[taken][i][j],combos[j][k]));
                }
            }
        }
    }

    int result=0;
    int finalmask = (1<<n)-1;
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            if (i==j) continue;
            result = max(result,min(dp[finalmask][i][j],combosedge[i][j]));
        }
    }

    cout << result;

    return 0;
}

