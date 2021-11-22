#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;
typedef long long  ll;
 
ll dp[100005][11][3]; //[vertex][how many valuable chosen so far][0=value k, 1=value<k,2=value>k]
vector<int> adj[100005];


void dfs(int current, int parent,int x,int k,int m){
    dp[current][1][0] = (k>1) ? 1 : 0; //value k
    dp[current][0][1] = k-1; //value <k
    dp[current][0][2] = (m-k); //value>k

    for (int child : adj[current]){
        if (child == parent) continue;
        dfs(child,current,x,k,m);

        vector<vector<ll>> temp(x+1); //how many different possibilities for each i from child child
        for (int i=0;i<=x;++i) temp[i] = vector<ll>(3,0LL);

        for (int i=0;i<=x;++i){ //parent
            for (int j=0;j<=i;++j) { //child 
                    temp[i][2]+=dp[current][i-j][2]*(dp[child][j][2]+dp[child][j][1]) % MOD;
                    temp[i][1]+=dp[current][i-j][1]*(dp[child][j][1]+dp[child][j][2]+dp[child][j][0]) % MOD;
                    if (i>j) temp[i][0]+=dp[current][i-j][0]*dp[child][j][1] % MOD;
            }
        }
        for (int i=0;i<=x;++i){
            for (int j=0;j<=2;++j) dp[current][i][j] = temp[i][j] % MOD;
        }
    }
}

int main(){
    int n,m,k,x;
    cin >> n >> m;
    int u,v;
    for (int i=0;i<n-1;++i){
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> k >> x;

    ll result=0;
    dfs(1,-1,x,k,m);
    for (int i=0;i<=x;++i){
        result = (result + dp[1][i][0]) % MOD;
        result = (result + dp[1][i][1]) % MOD;
        result = (result + dp[1][i][2]) % MOD;
    }
    cout << result << endl;
    return 0;
}