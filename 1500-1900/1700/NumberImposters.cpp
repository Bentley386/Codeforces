#include<bits/stdc++.h>
 
using namespace std;

// https://codeforces.com/contest/1594/problem/D

using ll = long long;

constexpr ll INF = 2000000000;
constexpr ll MOD = 998244353;
constexpr int N = 205000;

int imp[N]; //1 crewmate, 2 imp, 0 not visited
int visited[N]; //for calcing comp size
vector<pair<int,int>> adj[N]; //1 have to be same


int dfs(int curr){ //return number of imposters if start is crewmate
    int num = imp[curr]-1;
    for (auto x : adj[curr]){
        if (imp[x.first] != 0){
            if ((x.second == 1 && imp[x.first] != imp[curr]) || (x.second == 0 && imp[x.first] == imp[curr])) return -1;
            else continue;
        }
        int res;
        if (x.second == 1){
            imp[x.first] = imp[curr];
            res = dfs(x.first);
        } else {
            imp[x.first] = (imp[curr]%2)+1;
            res = dfs(x.first);
        }
        if (res == -1) return -1;
        else num+=res;
    }
    return num;

}

int dfsSize(int curr){
    visited[curr] = 1;
    int currsize = 1;
    for (auto x : adj[curr]){
        if (visited[x.first]) continue;
        else currsize+= dfsSize(x.first);
    }
    return currsize;
}

void solve(){
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;++i) adj[i] = vector<pair<int,int>>();
    for (int i=0;i<m;++i){
        int u,v;
        scanf("%d %d",&u,&v);
        string s;
        getline(cin >> ws, s);
        if (s == "imposter"){
            adj[u].push_back({v,0});
            adj[v].push_back({u,0});
        } else {
            adj[u].push_back({v,1});
            adj[v].push_back({u,1});
        }
    }

    for (int i=1;i<=n;++i) {
        visited[i] = 0;
        imp[i] = 0;
    }

    int imposters = 0;
    for (int i=1;i<=n;++i){
        if (visited[i]) continue;
        imp[i] = 1; //crewmate
        int res = dfs(i);
        if (res == -1) {
            cout << "-1\n";
            return;
        }
        int siz = dfsSize(i);
        imposters+= max(res,siz-res);
    }
    cout << imposters << endl;
}

int main(){
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}