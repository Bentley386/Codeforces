#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1501/problem/B

typedef long long  ll;
 
#define N 100005
 
 
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;++i) scanf("%d",&a[i]);
    vector<bool> drench(n);
    for (int i=0;i<n;++i) drench[i] = false;
    int cream=0;
    for (int i=n-1;i>=0;--i){
        cream = max(a[i],cream-1);
        if (cream>0) drench[i]=true;
    }

    for (int i=0;i<n;++i) {
        printf("%d ",(drench[i]) ? 1 : 0);
    }
    cout << "\n";
}
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}