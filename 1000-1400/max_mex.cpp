#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1496/problem/B

typedef long long  ll;
 
#define N 100005
 
 
void solve(){
    int n,k;
    cin >> n >> k;
    set<int> a;
    for (int temp,i=0;i<n;++i){
        scanf("%d",&temp);
        a.insert(temp);  //0 1 4
    }
    int init = a.size(); //3
    if (k==0) {
        cout << init << "\n";
        return;
    }
    int mex;
    for (int i=0;i<=n;++i){
        if (a.count(i)) continue;
        mex=i; //2
        break;
    }
    if (mex==a.size()){
        cout << n + k << "\n";
        return; 
    }
    int maxi = *(--a.end()); 
    a.insert((maxi+mex)/2 + ((maxi+mex)%2!=0)); 
    for (int i=0;i<=n;++i){
        if (a.count(i)) continue;
        mex=i;
        break;
    }
    if (mex==a.size()){
        cout << a.size() + k - 1 << "\n";
        return; 
    }
    cout << a.size() << "\n";
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}