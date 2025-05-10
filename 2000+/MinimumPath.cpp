#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1473/problem/E

typedef long long  ll;
 
const int N = 200005;
vector<pair<int,int>> adj[N];
ll distances[N][2][2];
int visited[N][2][2];
 
void solve(){
    int n,m;
    cin >> n >> m;
    for (int i=0;i<m;++i){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
 
    for (int i=1;i<=n;++i){
        for (int j=0;j<2;++j){
            for (int k=0;k<2;++k) distances[i][j][k] = INF;
        }
    }
    
    priority_queue<pair<ll,tuple<int,int,int>>> q; // distance, node, f1,f2
    q.push({0,make_tuple(1,0,0)});
    while (!q.empty()){
        ll dist = -q.top().first;
        tuple<int,int,int> info = q.top().second;
        q.pop();
        int vertex = get<0>(info);
        int f1 = get<1>(info); //skip one
        int f2 = get<2>(info); //take twice
        if (visited[vertex][f1][f2]) continue;
        visited[vertex][f1][f2] = 1;
        distances[vertex][f1][f2] = dist;
 
        for (auto x : adj[vertex]){
            if (f1 == 0){
                if (dist < distances[x.first][1][f2]) q.push({-dist,make_tuple(x.first,1,f2)});
            }
            if (f2 == 0){
                if (dist+2*x.second < distances[x.first][f1][1]) q.push({-dist-2*x.second,make_tuple(x.first,f1,1)});
            }
            if (dist+x.second < distances[x.first][f1][f2]) q.push({-dist-x.second,make_tuple(x.first,f1,f2)});
            if (f1 == 0 && f2 == 0){
                if (dist+x.second < distances[x.first][1][1]) q.push({-dist-x.second,make_tuple(x.first,1,1)});
            }
        }
    }
    for (int i=2;i<=n;++i){
        cout << distances[i][1][1] << " ";
    }
 
}
 
int main(){
    solve();
    return 0;
}