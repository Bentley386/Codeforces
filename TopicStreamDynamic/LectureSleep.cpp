#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/gym/302977/problem/D

typedef long long  ll;
 
#define N 100005
 
int dp[8]; //represents subsets of {A,B,C}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n),t(n);
    for (int i=0;i<n;++i) scanf("%d",&a[i]);
    for (int i=0;i<n;++i) scanf("%d",&t[i]);
    vector<int> pSleepy(n),pWake(n); //how many theorems from 0 to i
    pSleepy[0] = (t[0]==1) ? a[0] : 0;
    pWake[0] = a[0];
    for (int i=1;i<n;++i){
        if (t[i]==1) pSleepy[i] = a[i]+pSleepy[i-1];
        else pSleepy[i] = pSleepy[i-1];
        pWake[i] = a[i]+pWake[i-1];
    }
    int total = pSleepy[n-1];
    int maxi = total;
    for (int i=0;i<n-k+1;++i){
        if (i==0){
            maxi = max(maxi,pWake[k-1]+total-pSleepy[k-1]);
        } else {
            maxi = max(maxi,pWake[i+k-1]-pWake[i-1]+pSleepy[i-1]+total-pSleepy[i+k-1]);
        }
    }
    cout << maxi << endl;
}