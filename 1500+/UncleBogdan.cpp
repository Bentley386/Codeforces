#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>
#include<cmath>
#include<unordered_set>

#define INF 100000000
#define MOD 998244353
using namespace std;
typedef long long  ll;
const int N=100010;
int p[N],h[N],pcum[N],g[N];
vector<int> adj[N];

int dfs(int prev,int node);
bool dfs2(int prev,int node);

int main(){
    int t,n,m;
    cin >> t;
    while(t--){
        scanf("%d %d",&n,&m); 
        for (int i=1;i<=n;i++) scanf("%d",p+i); 
        for (int i=1;i<=n;i++) scanf("%d",h+i); 
        int x,y;
        for(int i=0;i<n-1;i++){
            scanf("%d %d",&x,&y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(1,1);
        if (dfs2(1,1)) cout << "YES\n";
        else cout << "NO\n";
        for (int i = 1;i<=n;i++){
            p[i]=0; 
            h[i]=0;
            pcum[i]=0;
            g[i]=0;
            adj[i]=vector<int>();
        }
    }

    return 0;
}

int dfs(int prev, int node){
    int peeps=p[node];
    for (const int& x : adj[node]){
        if(x == prev) continue;
        peeps+=dfs(node,x);
    }
    pcum[node]=peeps;
    return peeps;
}
bool dfs2(int prev, int node){
    int pop = pcum[node]; 
    int happiness = h[node]; 
    if (pop+happiness < 0) return false;
    if ((pop+happiness) % 2 == 1) return false;
    int good = (pop+happiness)/2;
    g[node] = good;
    if(good > pop || good < 0) return false;
    ll sumgood=0;
    for (const int& x : adj[node]){
        if (x == prev) continue;
        if (!dfs2(node,x)) return false;
        sumgood += (ll)g[x];
    }
    if (sumgood>good) return false;
    return true;
}