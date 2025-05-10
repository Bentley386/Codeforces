#include<bits/stdc++.h>

#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1286/problem/B

typedef long long  ll;

vector<int> tree[2010];
int cs[2010],ps[2010];

int numDesc(int node){
    int descendants = 0;
    for (int x : tree[node]) {
        descendants += 1 + numDesc(x);
    }
    if (descendants < cs[node]) return 10000;
    return descendants;
}

void solve(int node, vector<int>& order){
    ps[node] = order[cs[node]];
    order.erase(order.begin()+cs[node]);

    for (int x : tree[node])
        solve(x,order);
}

int main(){
    int n;
    cin >> n;
    int root;
    for (int i=1;i<=n;i++){
        int p,c;
        cin >> p >> c;
        cs[i]=c;
        if (p==0){
            root=i;
            continue;
        }
        tree[p].push_back(i);
    }
    if (numDesc(root) > 5000) cout << "NO";
    else {
        vector<int> order(n);
        order[0]=1;
        for (int i =1;i<n;i++) order[i]=order[i-1]+1;
        solve(root,order);
        cout << "YES\n";
        for (int i=1;i<n;i++) cout << ps[i] << " ";
        cout << ps[n];
    }

    return 0;
}