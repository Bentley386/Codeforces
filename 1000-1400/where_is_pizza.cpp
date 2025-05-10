#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
#define N 500005

using namespace std;

// https://codeforces.com/contest/1670/problem/C


typedef long long  ll;

int a[N],b[N];
vector<int> adj[N];
bool visited[N], marked[N];

int dfs(int node){
    visited[node] = true;
    int val = (marked[node]) ? 1 : 2;
    for (int x : adj[node]){
        if (visited[x]) continue;
        val = min(val,dfs(x));
    }
    return val;
}

void solve(){
    int n; cin >> n;
    for (int i=0;i<n;++i) cin >> a[i];
    for (int i=0;i<n;++i) cin >> b[i];
    for (int i=0;i<n;++i) visited[i] = false;
    for (int i=0;i<n;++i) marked[i] = false;

    for (int d,i=0;i<n;++i) {
        cin >> d;
        if (d!=0) {
            marked[a[i]-1] = true;
            marked[b[i]-1] = true;
        }
    }

    for (int i=0;i<n;++i) adj[i] = vector<int>();
    for (int i=0;i<n;++i){
        if (a[i] == b[i]) {
            visited[a[i]-1] = true;
            continue;
        }
        adj[a[i]-1].push_back(b[i]-1);
        adj[b[i]-1].push_back(a[i]-1);
    }
    ll result = 1;
    for (int i=0;i<n;++i){
        if (visited[i]) continue;
        result = result*dfs(i) % MOD;
    }
    cout << result << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();
    return 0;
} 