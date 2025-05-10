#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;

// https://codeforces.com/gym/304970/problem/E

typedef long long  ll;
 
#define N 200005

vector<int> adj[N];
ll costs[N];
ll subtreeSums[N];
ll a[N];

ll calcSums(int curr, int prev){
    ll sum = a[curr];
    for (int x : adj[curr]) {
        if (x==prev) continue;
        sum += calcSums(x,curr);
    }
    subtreeSums[curr] = sum;
    return sum;
}

ll calcRoot(int curr, int prev, int dist) {
    ll cost = a[curr]*dist;
    for (int x : adj[curr]){
        if (x == prev) continue;
        cost += calcRoot(x,curr,dist+1);
    }
    return cost;
}

void calcAll(int curr, int prev, ll cost){
    costs[curr] = cost;
    for (int x : adj[curr]){
        if (x == prev) continue;
        calcAll(x,curr, cost - subtreeSums[x] + (subtreeSums[1]-subtreeSums[x]));
    }
}

int main(){
    int n; cin >> n;
    for (int i=1;i<=n;++i) scanf("%ld",a+i);
    for (int i=0;i<n-1;++i) {
        int u,v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    costs[1] = calcRoot(1,-1,0);
    calcSums(1,-1);
    calcAll(1,-1, costs[1]);
    cout << *max_element(costs, costs+n+1) << endl;
    return 0;
}