#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;

// https://codeforces.com/gym/302977/problem/G

typedef long long  ll;
 
#define N 100005

int dp[105][2000]; //max distance travelled so far if at time 1 we have speed 2

int main(){
    int v1, v2;
    cin >> v1 >> v2;
    int t,maxd;
    cin >> t >> maxd;
    dp[1][v1] = v1;
    for (int i=2;i<=t;++i){
        for (int v=1;v<=1000;++v){
            for (int d=0;d<=maxd;++d){
                if (dp[i-1][v] == 0) continue;
                dp[i][v+d] = max(dp[i][v+d],dp[i-1][v]+v+d);
                if (v-d > 0) dp[i][v-d] = max(dp[i][v-d],dp[i-1][v]+v-d);
            }
        }
    }
    cout << dp[t][v2] << endl;
}