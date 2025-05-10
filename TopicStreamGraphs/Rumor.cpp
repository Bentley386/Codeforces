#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/gym/317667/problem/B

typedef long long  ll;

#define N 100005

int c[N];
vector<int> adj[N];
bool visited[N];

int dfs(int curr){
    int value = c[curr];
    visited[curr] = true;
    for (int x : adj[curr]){
        if (visited[x]) continue;
        value = min(value,dfs(x));
    }
    return value;
}

int main(){
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;++i) scanf("%d",c+i);
    for (int x,y,i=0;i<m;++i){
        scanf("%d %d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ll result = 0;
    for (int i=1;i<=n;++i){
        if (visited[i]) continue;
        result += dfs(i);
    }
    cout << result << endl;
    return 0;
}