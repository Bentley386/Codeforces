#include<bits/stdc++.h>
 
using namespace std;

// https://codeforces.com/contest/1582/problem/F1

using ll = long long;

constexpr ll INF = 2000000000;
constexpr ll MOD = 1000000007;
constexpr int N = 100005;

int a[N];
int dp[520]; //dp[i] lowest ending number that gives xor i

void solve(){
    int n; cin >> n;
    for (int i=0;i<n;++i) scanf("%d",a+i);
    for (int i=0;i<520;++i) dp[i]= INF;

    for (int i=0;i<n;++i){
        dp[a[i]] = min(dp[a[i]],a[i]);
        for (int j=0;j<520;++j){
            if (dp[j] < a[i]) dp[j^a[i]] = min(dp[j^a[i]],a[i]);
        }
    }
    dp[0] = 0;
    int num = 0;
    for (int i=0;i<520;++i) {
        if (dp[i] < INF) num++;
    }
    cout << num << endl;
    for (int i=0;i<520;++i){
        if (dp[i]<INF) cout << i << " ";
    }
}

int main(){
    solve();
    return 0;
}