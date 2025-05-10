#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1485/problem/A

typedef long long  ll;
 
 
void solve(){
    int a,b;
    cin >> a >> b;
    int best = INF;
    for (int i=0;i<100;++i){
        int aa=a;
        int bb=b;
        int steps=i;
        bb+=i;
        if (bb==1){
            continue;
        }
        while (aa!=0){
            aa = aa/bb;
            steps++;
        }
        best = min(best,steps);
    }
    cout << best << "\n";
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}