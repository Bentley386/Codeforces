#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;

// https://codeforces.com/gym/302977/problem/A

typedef long long  ll;
 
#define N 100005
 
int dp[50];

int main(){
    int n;
    cin >> n;
    if (n%2==1) cout << "0\n";
    else {
        dp[0]=2;
        for (int i=1;i<n/2;++i){
            dp[i] = dp[i-1]*2;
        }
        cout << dp[n/2-1] << endl;
    }
    return 0;
}