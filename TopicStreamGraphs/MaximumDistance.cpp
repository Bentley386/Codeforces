#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;

// https://codeforces.com/gym/317667/problem/H

typedef long long  ll;

#define N 100005

set<int> spec;

int rep[N];
int sizes[N];
vector<pair<int,int>> adj[N];

bool relevant[N]; //true if subtree at i has >0 spec vertex
int farthest, farthestDist=.1;

void dfsFindFarthest(int curr, int prev, int distance){
    if (spec.count(curr) && distance > farthestDist) {
        farthestDist = distance;
        farthest = curr;
    }
    for (auto x : adj[curr]){
        if (x.first == prev) continue;
        dfsFindFarthest(x.first,curr,distance+1);
    }

}

bool dfsFindRel(int curr, int prev){
    bool rel = spec.count(curr);
    for (auto x : adj[curr]) {
        if(x.first == prev) continue;
        rel |= dfsFindRel(x.first,curr);
    }
    relevant[curr] = rel;
    return rel;
}

int dfsSolve(int curr, int prev){
    int maxim = -1;
    for (auto x : adj[curr]){
        if (!relevant[x.first] || x.first == prev) continue;
        maxim = max(maxim,x.second);
        maxim = max(maxim,dfsSolve(x.first,curr));
    }
    return maxim;
}

int findRep(int x){
    while (x != rep[x]) x = rep[x];
    return x;
}

bool same(int x, int y){
    return (findRep(x) == findRep(y));
}

void unite(int x, int y){
    x = findRep(x); y = findRep(y);
    if (sizes[x] > sizes[y]) swap(x,y);
    sizes[y] += sizes[x];
    rep[x] = y;
}

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    for (int temp,i=0;i<k;++i) {
        scanf("%d",&temp);
        spec.insert(temp);
    }

    vector<tuple<int,int,int>> edges;
    for (int u,v,w,i=0;i<m;++i){
        scanf("%d %d %d",&u,&v,&w);
        edges.push_back(make_tuple(w,u,v));
    }

    for (int i=1;i<=n;++i) {
        sizes[i] = 1;
        rep[i] = i;
    }

    sort(edges.begin(),edges.end());
    int u,v;
    for (auto x : edges){
        u=get<1>(x); v=get<2>(x);
        if (!same(u,v)){
            unite(u,v);
            int w = get<0>(x);
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
    }
    dfsFindFarthest(1,-1,0);
    dfsFindRel(farthest,-1);
    int result = dfsSolve(farthest,-1);
    for (int i=0;i<k;++i) cout << result << " ";

    return 0;
}