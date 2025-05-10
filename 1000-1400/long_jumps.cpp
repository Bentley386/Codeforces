#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1472/problem/C

typedef long long  ll;
 
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    ll maxscore=-1;
    for (int i=0;i<n;++i) scanf("%d",&a[i]);
    vector<ll> scores(n,0);
    for (int i=n-1;i>=0;--i){
        if(i+a[i] < n) scores[i] = (ll)a[i]+scores[i+a[i]];
        else scores[i] = a[i];
        maxscore = max(maxscore,scores[i]);
    }
    cout << maxscore << "\n";
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
