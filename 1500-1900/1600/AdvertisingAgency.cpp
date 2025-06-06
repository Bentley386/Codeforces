#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 1000000007
using namespace std;

// https://codeforces.com/contest/1475/problem/E

typedef long long  ll;
 
#define N 1010
int bin[N][N];
bool have[N][N];
 
int calculate(int n,int k){
    if (have[n][k]) return bin[n][k];
    have[n][k] = true;
    if (k==1) bin[n][k] = n;
    else if (k==0 || n==k) bin[n][k] = 1;
    else if (n<k) bin[n][k] = 0;
    else bin[n][k] = (calculate(n-1,k-1) + calculate(n-1,k)) % MOD;
    return bin[n][k];
}
void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> a = vector<int>(n);
    for (int i=0;i<n;++i) cin >> a[i];
    sort(a.begin(),a.end());
    int last = a[n-1];
    int count=1;
    for (int i=1;i<k;++i){
        if (a[n-1-i] == last) count++;
        else {
            last = a[n-1-i];
            count = 1;
        }
    }
    int total = upper_bound(a.begin(),a.end(),last)-lower_bound(a.begin(),a.end(),last);
    cout << calculate(total,count) << endl;
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}