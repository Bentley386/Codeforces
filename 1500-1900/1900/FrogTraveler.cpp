#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;

// https://codeforces.com/contest/1602/problem/D

typedef long long  ll;

#define N 300005
int a[N],b[N];
vector<int> adj[N];
int dist[N];
bool visited[N];
bool visited2[N];
int fastest[N];
int afterjump[N];
int n;

void bfs(){
    queue<int> next;
    next.push(n);
    dist[n] = 0;
    visited[n] = true;
    while (!next.empty()){
        int curr = next.front();
        next.pop();
        for (int x,i=a[curr];i>=1;--i){
            if (visited2[curr-i]) break;
            visited2[curr-i] = true;
            if (curr-i == 0) x = 0;
            else  x = curr-i+b[curr-i];
            if (!visited[x]) {
                visited[x] = true;
                fastest[x] = curr;
                afterjump[x] = curr-i;
                dist[x] = dist[curr]+1;
                next.push(x);
            }
        }
    }
}

int main(){
    cin >> n;
    for (int i=1;i<=n;++i) scanf("%d",a+i);
    for (int i=1;i<=n;++i) scanf("%d",b+i);
    bfs();
    if (!visited[0]) cout << "-1\n";
    else {
        cout << dist[0] << "\n";
        vector<int> seq;
        int curr=0;
        while (curr != n){
            seq.push_back(afterjump[curr]);
            curr = fastest[curr];
        }
        for (int i=seq.size()-1;i>=0;--i){
            cout << seq[i] << " ";
        }

    }
    return 0;
}