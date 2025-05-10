#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/gym/317667/problem/C

typedef long long  ll;

#define N 500005

int sizes[N];
int repr[N];

int findRep(int node){
    while (repr[node] != node){
        node = repr[node];
    }
    return node;
}

bool same(int first, int second){
    return (findRep(first) == findRep(second));
}

void unite(int first, int second){
    first = findRep(first); second = findRep(second);
    if (sizes[first] > sizes[second]) swap(first,second);
    repr[first] = second;
    sizes[second] += sizes[first];
}

int main(){
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;++i){
        sizes[i] = 1;
        repr[i] = i;
    }
    for (int i=0;i<m;++i){
        int k;
        scanf("%d",&k);
        if (k==0) continue;
        int first;
        scanf("%d",&first);
        for (int curr,j=0;j<k-1;++j){
            scanf("%d",&curr);
            if (!same(first,curr)) unite(first,curr);
        }
    }
    for (int i=1;i<=n;++i){
        cout << sizes[findRep(i)] << " ";
    }
    return 0;
}