#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;
typedef long long  ll;
 
#define N 200005

vector<int> adj[N];
int n;
int depths[N];
int parent[N];
int anc[N][20]; //[vertex][2^[i]th anc]

void dfsAncs(int curr, int prev){
    for (int x : adj[curr]){
        if (x==prev) continue;
        anc[x][0] = curr;
        dfsAncs(x,curr);
    }
}
void populateAnc(){
    dfsAncs(1,-1);
    for (int k=1;k<20;++k){
        for (int i=1;i<=n;++i){
            anc[i][k] = anc[anc[i][k-1]][k-1];
        }
    }
}

void calcDepth(int curr, int prev, int depth){
    parent[curr] = prev;
    depths[curr] = depth;
    for (int x : adj[curr]){
        if ( x == prev) continue;
        calcDepth(x,curr,depth+1);
    }
}

int ancestor(int x, int k){
    int result = x;
    int powr;
    while (k!=0){
        powr = k & (-k);
        k-=powr;
        result = anc[result][__builtin_ctz(powr)];
    }
    return result;
}

int lca(int x, int y){
    if (depths[x] > depths[y]) x = ancestor(x,depths[x]-depths[y]);
    else y = ancestor(y,depths[y]-depths[x]);
    //find first k such that anc(x,k) == anc(y,k)
    int left=0, right=depths[x];
    int mid = (left+right)/2;
    while (left <= right) {
        mid = (left+right)/2;
        if (ancestor(x,mid) == ancestor(y,mid)){
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
    if (ancestor(x,mid) == ancestor(y,mid)) return ancestor(x,mid);
    else return ancestor(x,mid+1);
}

int main(){
    int m; 
    cin >> n >> m;
    for (int i=0;i<n-1;++i){
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    populateAnc();
    calcDepth(1,-1,0);
    for (int i=0;i<m;++i){
        int k; cin >> k;
        vector<int> verts(k);

        int maxVert = -1;
        int maxDepth = -1;

        for (int i=0;i<k;++i){
            scanf("%d", &verts[i]);
            if (depths[verts[i]] > maxDepth){
                maxDepth = depths[verts[i]];
                maxVert = verts[i];
            }
        }
        bool path = true;
        for (int i=0;i<k;++i){
            if (verts[i] == maxVert) continue;
            int lc = lca(verts[i],maxVert);
            if (lc != verts[i] && parent[verts[i]] != lc) {
                path = false;
                break;
            }
        }
        if (path) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}