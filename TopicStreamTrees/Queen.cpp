#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;

// https://codeforces.com/gym/304970/problem/A

typedef long long  ll;

#define N 100005
vector<int> toDelete;
vector<int> children[N];
int respect[N];

void dfs(int curr){
    int viable = respect[curr];
    for (int x : children[curr]){
        viable &= respect[x];
        dfs(x);
    }
    if (viable) toDelete.push_back(curr);
}

int main(){
    int n; cin >> n;
    int root=-1;
    for (int i=1;i<=n;++i){
        int p,c;
        scanf("%d %d",&p,&c);
        if (p == -1){
            root=i;
        } else {
            children[p].push_back(i);
        }
        respect[i] = c;
    }

    dfs(root);
    if (toDelete.size() == 0) cout << "-1\n";
    else {
        sort(toDelete.begin(),toDelete.end());
        for (int x : toDelete) cout << x << " ";
    }


    return 0;
}
 