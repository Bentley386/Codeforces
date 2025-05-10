#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/gym/317667/problem/D

typedef long long  ll;

#define N 100005

bool visited[N];
int colors[N];
vector<int> adj[N];

bool dfs(int prev, int node, int color){
    bool cool = true;
    visited[node]=true;
    colors[node] = color;
    for (int x : adj[node]){
        if (x == prev) continue;
        if (visited[x]) {
            if (colors[x] == colors[node]) return false;
            else continue;
        }
        cool &= dfs(node,x,1-color);
    }
    return cool;
}

int main(){
    int n,m;
    cin >> n >> m;
    for (int u,v,i=0;i<m;++i){
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool bipartite = true;
    for (int i=1;i<=n;++i){
        if (visited[i]) continue;
        bipartite &= dfs(-1,i,0);
    }
    if (! bipartite) {
        cout << "-1\n";
    } else {
        vector<int> a,b;
        for (int i=1;i<=n;++i){
            if (colors[i] == 0) a.push_back(i);
            else b.push_back(i);
        }
        cout << a.size() << '\n';
        for (int x : a) cout << x << " ";
        cout << '\n' << b.size() << '\n';
        for (int x : b) cout << x << " ";

    }
    return 0;
}