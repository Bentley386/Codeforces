#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1420/problem/C1

typedef long long  ll;
 
int main(){
    int t,n,q;
    cin >> t;
    while (t--){
        cin >> n >> q;
        vector<int> a(n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        vector<vector<ll>> dp(n+1);
        dp[0] = {0,0,0,0}; //{v item pristejemo, v item odstejemo, i-tega preskocimo nazadnje pristeli, i-tega preskocimo nazadnje odesteli}
        for (int i=0;i<n;i++){
            dp[i+1] = vector<ll>(4);
            dp[i+1][0] = max(dp[i][1],dp[i][3])+a[i];
            dp[i+1][1] = max(dp[i][0],dp[i][2])-a[i];
            dp[i+1][2] = max(dp[i][0],dp[i][2]);
            dp[i+1][3] = max(dp[i][1],dp[i][3]);
        }
        cout << *max_element(dp[n].begin(),dp[n].end()) << endl;
    }
    return 0;
}