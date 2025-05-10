#include<bits/stdc++.h>
 
using namespace std;

// https://codeforces.com/contest/1637/problem/D

using ll = long long;

constexpr ll INF = 2000000000;
constexpr ll MOD = 1000000007;
constexpr int N = 105;

int a[N],b[N];
bool dp[N][N*N];


// (ai+aj)^2 = (n-2)ai^2 +sum(a)^2

void solve(){
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    for (int i=1;i<=n;++i) cin >> b[i];
    if (n==1){
        cout << "0\n";
        return;
    }
    for (int i=0;i<=n;++i){
        for (int j=0;j<(105)*n;++j) dp[i][j] = false;
    }
    int conpart = 0;
    int totalsum = 0;
    int suma = 0;
    for (int i=1;i<=n;++i){
        conpart += (n-2)*a[i]*a[i] + (n-2)*b[i]*b[i];
        totalsum += a[i]+b[i];
        suma += a[i];
    }

    dp[0][suma] = true;
    for (int i=1;i<=n;++i){
        int change = b[i]-a[i];
        for (int j=0;j<(105)*n;++j){
            dp[i][j] |= dp[i-1][j];
            if (j+change >=0) dp[i][j+change] |= dp[i-1][j];
        }
    }
    
    int mini = suma*suma + (totalsum-suma)*(totalsum-suma);
    for (int j=0;j<(105)*n;++j){
        if (dp[n][j]){
            mini = min(mini,j*j+(totalsum-j)*(totalsum-j));
        }
    }
    cout << mini + conpart << endl;

}

int main(){
    int t; cin >> t;
    while (t--)
    solve();
    return 0;
}