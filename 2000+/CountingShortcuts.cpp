#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
#define N 200005

using namespace std;

// https://codeforces.com/contest/1650/problem/G

typedef long long  ll;
vector<int> adj[N],atDist[N];
ll dp[N][2]; //number of ways to get from s to [1]
int dist[N];

void solve(){
    int n,m;
    cin >> n >> m;
    int s,t;
    cin >> s >> t;
    for (int i=0;i<=n;++i) {
        adj[i] = vector<int>();
        atDist[i] = vector<int>();
    }
    for (int i=0;i<m;++i){
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1;i<=n;++i){
        dp[i][0]=0; //num of ways to get to i in shortest route
        dp[i][1]=0; //num of ways to get to i in shortest+1
        dist[i] = INF;
    }
    dp[s][0] = 1;
    dist[s] = 0;
    atDist[0].push_back(s);
    queue<int> q;
    q.push(s);
    while (!q.empty()){
        int curr = q.front(); q.pop();
        for (int x : adj[curr]){
            if (dist[x] < INF) continue;
            dist[x] = dist[curr]+1;
            q.push(x);
            atDist[dist[x]].push_back(x);
        }
    }
    for (int i=1;i<=dist[t];++i){
        for (int x : atDist[i]){
            for (int y : adj[x]){
                if (dist[y] == i-1) {
                    dp[x][0] = (dp[x][0] + dp[y][0]) % MOD;
                }
            }
        }
    }

    for (int i=1;i<=dist[t];++i){
        for (int x : atDist[i]){
            for (int y : adj[x]){
                if (dist[y] == i-1) {
                    dp[x][1] = (dp[x][1] + dp[y][1]) % MOD;
                } else if (dist[y] == i){
                    dp[x][1] = (dp[x][1] + dp[y][0]) % MOD;
                }
            }
        }
    }
    cout << (dp[t][0]+dp[t][1])%MOD << endl;


}

int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
} 