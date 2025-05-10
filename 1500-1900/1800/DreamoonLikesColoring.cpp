#include<bits/stdc++.h>

#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1329/problem/A

typedef long long  ll;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> Ls(m);
    for (int i=0;i<m;i++) scanf("%d",&Ls[i]);
    vector<ll> LsSum(m);
    LsSum[m-1]=Ls[m-1];
    for (int i=m-2;i>=0;i--){
        LsSum[i] = LsSum[i+1] + Ls[i];
    }
    if (LsSum[0] < n) {
        cout << -1;
        return 0;
    }
    for(int i=0;i<m;i++){
        if (Ls[i]+i > n) {
            cout << -1;
            return 0;
        }
    }
    for (int i=0;i<m;i++){
        cout << max((ll)i+1,n-LsSum[i]+1);
        if (i<m-1) cout << " ";
    }
    return 0;
}