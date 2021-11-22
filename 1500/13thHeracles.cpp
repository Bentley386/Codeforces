#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;
typedef long long  ll;
 
int degrees[205000];
 
void solve(){
    int n;
    ll sum=0;
    cin >> n;
    vector<pair<int,int>> w(n);
 
    for(int ww,i=0;i<n;++i) {
        scanf("%d",&ww);
        sum += ww;
        w[i] = {ww,i+1};
    }
    for (int u,v,i=0;i<n-1;++i){
        scanf("%d %d",&u,&v);
        degrees[u]++;
        degrees[v]++;
    }
    int count = 1;
    cout << sum << " ";
    sort(w.rbegin(),w.rend());
    for (int i=0;i<n;++i){
        if (degrees[w[i].second]==1) continue;
        while (degrees[w[i].second]-- > 1){
            sum += w[i].first;
            cout << sum << " ";
            count++;
        }
    }
 
    for (int i=0;i<=n;++i) degrees[i] = 0;
    for (int i=0;i<n-1-count;++i) cout << sum << " ";
    cout << "\n";
 
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}