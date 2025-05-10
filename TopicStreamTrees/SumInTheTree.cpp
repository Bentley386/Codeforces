#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;

// https://codeforces.com/gym/304970/problem/C

typedef long long  ll;

#define N 100005

vector<int> children[N];
int s[N];
int values[N];


bool dfsCheck(int curr, int lastsum){
    if (s[curr] != -1 && s[curr] < lastsum) return false;
    bool allgood=true;
    for (int x : children[curr]){
        if (s[curr] == -1) allgood &= dfsCheck(x,lastsum);
        else allgood &= dfsCheck(x,s[curr]);
    }
    return allgood;
}


void dfsPopulate(int curr, int lastsum){
    if (s[curr] == -1){
        if (children[curr].size() == 0) return;
        int minimal = INF;
        for (int x : children[curr]) minimal = min(minimal,s[x]-lastsum);
        values[curr]=minimal;
        for (int x : children[curr]) {
            values[x] = s[x]-lastsum-minimal;
            dfsPopulate(x,lastsum+minimal);
        }
    } else {
        for (int x : children[curr]){
            dfsPopulate(x,lastsum+values[curr]);
        }
    }
}

int main(){
    int n; cin >> n;
    for (int i = 2;i<=n;++i){
        int p;
        scanf("%d",&p);
        children[p].push_back(i);
    }
    for (int i=1;i<=n;++i) scanf("%d",s+i);
    if (!dfsCheck(1,0)) {
        cout << "-1\n";
        return 0;
    }
    values[1] = s[1];
    dfsPopulate(1,0);
    ll result = 0;
    for (int i=1;i<=n;++i) result += values[i];
    cout << result;
    return 0;
}
 