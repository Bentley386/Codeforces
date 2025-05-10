#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/gym/317667/problem/F

typedef long long  ll;

#define N 300005

int state[N];
vector<int> adj[N];
vector<int> topSort;
int values[N];
int dp[N][30]; //[vertex][character]

bool dfs(int curr){
    if (state[curr]==2) return true;

    bool acyclic = true;
    state[curr] = 1;
    for (int x : adj[curr]){
        if (state[x] == 1) return false;
        acyclic &= dfs(x);
    }
    state[curr] = 2;
    topSort.push_back(curr);
    return acyclic;
}

int main(){
    int n,m;
    cin >> n >> m;
    cin >> ws;
    char c;
    for (int i=1;i<=n;++i){
        scanf("%c",&c);
        values[i] = c-'a';
    }
    for (int x,y,i=0;i<m;++i){
        scanf("%d %d",&x,&y);
        adj[x].push_back(y);
    }

    bool acyclic = true;
    for (int i=1;i<=n;++i) {
        if (state[i] == 2) continue;
        acyclic &= dfs(i);
    }
    if (!acyclic) {
        cout << "-1\n";
        return 0;
    }

    reverse(topSort.begin(),topSort.end());


    int runningMax = 0;
    for (int x : topSort) {
        dp[x][values[x]]++;
        runningMax = max(runningMax,dp[x][values[x]]);
        for (int y : adj[x]) {
            for (int i=0;i<26;++i) dp[y][i] = max(dp[y][i],dp[x][i]);
        }
    }
    cout << runningMax << endl;
    return 0;
}