#include<bits/stdc++.h>
 
using namespace std;

// https://codeforces.com/contest/1338/problem/B

using ll = long long;

constexpr ll INF = 2000000000;
constexpr ll MOD = 1000000007;
constexpr int N = 100005;

vector<int> adj[N];

bool dfs(int curr, int prev, int count){
    bool allGood = true;
    if (adj[curr].size() == 1 && count % 2 == 1) return false;
    for (int x : adj[curr]){
        if (x == prev) continue;
        allGood &= dfs(x,curr,count+1);
    }
    return allGood;
}

int dfs2(int curr, int prev){
    int counter=1;
    int leaves=0;
    for(int x : adj[curr]){
        if (x == prev) continue;
        if (adj[x].size() == 1){
            leaves++;
            continue;
        }
        counter += dfs2(x,curr);
    }
    if (leaves == adj[curr].size()) return 2;
    else if (leaves>0) return counter+1;
    else return counter;
}

void solve(){
    int n; cin >> n;
    for (int i=0;i<n-1;++i){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int nonleaf,leaf;
    for (int i=1;i<=n;++i){
        if (adj[i].size() > 1){
            nonleaf = i;
        } else {
            leaf = i;
        }
    }
    if (dfs(leaf,-1,0)) cout << "1 ";
    else cout << "3 ";
    cout << dfs2(nonleaf,-1)-1 << "\n";
}

int main(){
    solve();
    return 0;
}