#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1496/problem/C

typedef long long  ll;
 
#define N 100005
 
 
void solve(){
    int n;
    cin >> n;
    vector<int> mines(n),miners(n);
    int minec=0, minerc=0;
    for (int i=0;i<2*n;++i){
        int x,y;
        scanf("%d %d",&x,&y);
        if (x==0) miners[minerc++] = abs(y);
        else mines[minec++] = abs(x);
    }
    sort(mines.begin(),mines.end());
    sort(miners.begin(),miners.end());
    double energy = 0;
    for (int i=0;i<n;++i){
        energy += sqrt((double)mines[i]*mines[i] + (double)miners[i]*miners[i]);
    }
    printf("%.10f\n",energy);
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}