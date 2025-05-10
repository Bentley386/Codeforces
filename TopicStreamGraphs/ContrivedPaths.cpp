#include<bits/stdc++.h>
 
#define INF 1000000000000000000LL
#define MOD 998244353
using namespace std;

// https://codeforces.com/gym/317667/problem/G

typedef long long  ll;

#define N 100005
int a[N];
int b[15];
vector<pair<int,int>> adj[N];
bool visited[N];
ll dist[N];
int n,m,k;

void solve(int start){
    for (int i=1;i<=n+1;++i){
        visited[i]=false;
        dist[i] = INF;
    }
    priority_queue<pair<ll,int>> q;
    q.push({0,start});
    while(!q.empty()){
        int vert = q.top().second;
        ll d = -q.top().first;
        q.pop();
        if (visited[vert]) continue;
        visited[vert] = true;
        dist[vert] = d;
        for (auto x : adj[vert]){
            if (visited[x.first]) continue;
            if (d + x.second < dist[x.first]){
                q.push({-d-x.second,x.first});
            } 
        }
    }

    for (int i=1;i<=n;++i) cout << dist[i] << " ";
    cout << '\n';
}

int main(){
    cin >> n >> m >> k;
    for (int i=1;i<=n;++i){
        scanf("%d",a+i);
        adj[i].push_back({n+1,a[i]});
        adj[n+1].push_back({i,a[i]});
    }
    for (int u,v,w,i=0;i<m;++i){
        scanf("%d %d %d",&u,&v,&w);
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for (int i=0;i<k;++i) scanf("%d",b+i);
    for (int i=0;i<k;++i) solve(b[i]);

    return 0;
}