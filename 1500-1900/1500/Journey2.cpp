#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;
typedef long long  ll;

#define N 100005
vector<int> adj[N];

double dfs(int curr, int prev,double length){
    if (adj[curr].size() == 1 && prev != -1) return length;

    double result=0.0;
    double prob;
    if (curr == 1) prob = 1.0/(double) adj[curr].size();
    else prob = 1.0/(double) (adj[curr].size()-1);

    for (int x : adj[curr]) {
        if (x == prev) continue;
        result += prob*dfs(x,curr,length+1);
    }
    return result;
}
int main(){
    int n; cin >> n;
    for (int i=0;i<n-1;++i){
        int u,v;
        scanf("%d %d", &u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    double result = dfs(1,-1,0.0);

    cout << setprecision(15) << result;
    return 0;
}

