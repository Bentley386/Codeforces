#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;

// https://codeforces.com/gym/304970/problem/D

typedef long long  ll;
 
#define N 300005

vector<int> children[N];
int centroids[N];
int parent[N];
int sizes[N];

void calcSizes(int curr){
    int size = 1;
    for (int x : children[curr]){
        calcSizes(x);
        size+= sizes[x];
    }
    sizes[curr]=size;
}
void calcCentroids(int curr){
    if (sizes[curr] == 1) {
        centroids[curr] = curr;
        return;
    }
    for (int x : children[curr]) calcCentroids(x);
    int n = sizes[curr];
    for (int x : children[curr]){
        if (sizes[x] > n/2) {
            int p=centroids[x];
            while (n-sizes[p] > n/2) p = parent[p];
            centroids[curr] = p;
            return;
        }
    }
    centroids[curr] = curr;
}

int main(){
    int n,q;
    cin >> n >> q;
    for (int i=2;i<=n;++i){
        int p;
        scanf("%d",&p);
        children[p].push_back(i);
        parent[i] = p;
    }
    calcSizes(1);
    calcCentroids(1);
    for (int i=0;i<q;++i){
        int v;
        scanf("%d",&v);
        cout << centroids[v] << "\n";
    }


    return 0;
}