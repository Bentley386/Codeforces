#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1486/problem/B

typedef long long  ll;
 
 
void solve(){
    int n;
    cin >> n;
    vector<int> x(n),y(n);
    for (int i=0;i<n;++i){
        cin >> x[i];
        cin >> y[i];
    }
    if (n%2==1){
        cout << "1\n";
        return;
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    int resultx = x[n/2]-x[n/2-1]+1;
    int resulty = y[n/2]-y[n/2-1]+1;
    cout << (ll)resultx*resulty << "\n";
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}