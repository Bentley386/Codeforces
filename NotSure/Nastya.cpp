#include<bits/stdc++.h>

#define INF 1000000000
#define MOD 998244353
using namespace std;
typedef long long  ll;

set<int> pairs[300010];
int cue[300010];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> p(n);
    set<int> candidates;
    //vector<pair<int,int>> candidates;
    for (int i=0;i<n;i++) {
        scanf("%d",&p[i]);
        cue[p[i]] = i;
    }

    for (int i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        if (v==p[n-1]) candidates.insert(u);
        pairs[u].insert(v);
    }
    set<int> firmGuys;
    for (int i=n-2;i>=0;i--){
        int dude = p[i];
        if (candidates.count(dude)==0) 
            firmGuys.insert(dude);
        else {
            for (int x : firmGuys){
                if(pairs[dude].count(x) == 0) {
                    firmGuys.insert(dude);
                    break;
                }
            }
        }
    }
    cout << n-firmGuys.size()-1;
    return 0;
}