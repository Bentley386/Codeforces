#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;

// https://codeforces.com/contest/1602/problem/B

typedef long long  ll;

#define N 2005
int a[N];
int answers[N][N];

void solve(){
    int n; 
    cin >> n;
    for (int i=1;i<=n;++i) scanf("%d",a+i);
    map<int,int> counts;
    for (int j = 0; j<n+3;++j){
        for (int i=1;i<=n;++i){
            if (counts.count(a[i])) counts[a[i]]++;
            else counts[a[i]]=1;
            answers[j][i] = a[i];
        }
        for (int i=1;i<=n;++i){
            a[i] = counts[a[i]];
        }
        counts = map<int,int>();
    }


    int q; cin >> q;
    for (int x,k,i=0;i<q;++i){
        scanf("%d %d",&x,&k);
        if (k>n+2) k=n+2;
        cout << answers[k][x] << "\n";
    }
}

int main(){
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}