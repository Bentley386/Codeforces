#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/gym/302977/problem/C

typedef long long  ll;
 
#define N 100005
 
int dp[8]; //represents subsets of {A,B,C}

int main(){
    int n;
    cin >> n;
    for (int i=1;i<8;++i) dp[i] = INF;
    for (int i=0;i<n;++i){
        int cost;
        cin >> cost;
        string chars;
        cin >> chars;
        int mask=0; //representing vitamin content of i
        for (char c : chars){
            int pos = c-'A';
            mask |= (1<<pos);
        }    

        for (int j=0;j<8;++j){
            dp[j | mask] = min(dp[j |mask],dp[j]+cost);
        }
    }
    if (dp[7] == INF) cout << "-1\n";
    else cout << dp[7] << '\n';

}