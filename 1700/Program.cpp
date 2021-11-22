#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;
typedef long long  ll;
 
void solve(){
    int n,m;
    scanf("%d %d ",&n,&m);
    char c;
    vector<int> value(n),pmax(n),pmin(n);
    int curr=0,cmin=0,cmax=0;
    for (int i=0;i<n;++i){
        scanf("%c",&c);
        if (c=='+') curr++;
        else curr--;
        value[i] = curr;
        cmin = min(curr,cmin);
        pmin[i] = cmin;
        cmax = max(curr,cmax);
        pmax[i] = cmax;
    }
    vector<int> smax(n),smin(n);
    smax[n-1] = value[n-1];
    smin[n-1] = value[n-1];
    for (int i=n-2;i>=0;--i){
        smax[i] = max(smax[i+1],value[i]);
        smin[i] = min(smin[i+1],value[i]);
    }
    int l,r;
    int maxi,mini;
    for (int i=0;i<m;++i){
        scanf("%d%d",&l,&r);
        if (l==1 && r==n) {
            cout << "1" << endl;
            continue;
        } else if (r==n){
            maxi = max(0,pmax[l-2]);
            mini = min(0,pmin[l-2]);
        } else if (l==1){
            maxi = max(0,smax[r]-value[r-1]);
            mini = min(0,smin[r]-value[r-1]);
        } else { //1, 0, 1, 2
            maxi = max(0,pmax[l-2]); //0
            mini = min(0,pmin[l-2]); //-1
            maxi = max(maxi,smax[r]-value[r-1]+value[l-2]); //-2
            mini = min(mini,smin[r]-value[r-1]+value[l-2]);  //
        }
        cout << maxi-mini+1 << endl;
    }
}
 
int main(){
    int t;
    scanf("%d ",&t);
    while (t--){
        solve();
    }
    return 0;
}