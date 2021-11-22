#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;
typedef long long  ll;
 
#define N 200005
int a[N];
 
void solve(){
    int n;
    cin >> n;
    for (int i=0;i<n;++i) scanf("%d",a+i);
    n = min(n,5500);
    map<int,pair<int,int>> sums;
    for (int s,i=0;i<n;++i){
        for (int j=i+1;j<n;++j){
            s=a[i]+a[j];
            if (sums.count(s)){
                int x = sums[s].first;
                int y = sums[s].second;
                int z = i+1;
                int w = j+1;
                if (x != z && x != w && y != z && y != w){
                    printf("YES\n%d %d %d %d\n",x,y,z,w);
                    return;
                } 
            }
            sums[s] = {i+1,j+1};
        }
    }
    cout << "NO\n";
}
int main(){
    int t=1;
    //cin >> t;
    while (t--){
        solve();
    }
    return 0;
}