#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/gym/317667/problem/E

typedef long long  ll;

#define N 150005

bool visited[N];
bool visited2[N];
vector<int> adj[N];

int dfsComp(int prev, int curr){
    visited[curr] = true;
    int size = 1;
    for (int x : adj[curr]){
        if (visited[x]) continue;
        size += dfsComp(curr,x);
    }
    return size;
}

bool dfsCheck(int prev, int curr, int size){
    visited2[curr] = true;
    bool allgood=true;
    if (adj[curr].size() != size-1) return false;
    for (int x : adj[curr]){
        if (visited2[x]) continue;
        allgood &= dfsCheck(curr,x,size);
    }
    return allgood;
}

int main(){
    int n,m;
    cin >> n >> m;
    for (int u,v,i=0;i<m;++i){
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool reasonable = true;
    for (int i=1;i<=n;++i){
        if (visited[i]) continue;
        int size = dfsComp(-1,i);
        reasonable &= dfsCheck(-1,i,size);
    }
    if (reasonable) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}