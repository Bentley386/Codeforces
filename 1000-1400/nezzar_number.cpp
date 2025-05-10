#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1478/problem/B

typedef long long  ll;
 
 
void solve(){
    int q,d;
    cin >> q >> d;
    int maxim = 10*d;
    bool lucky[maxim];
    for (int i=0;i<maxim;++i){
        if (i%10 == d) lucky[i] = true;
        else lucky[i] = false;
    }
    for (int i=0;i<maxim;++i) {
        if (lucky[i]){
            for (int j=0;i+j<maxim;++j){
                if (lucky[j]) lucky[i+j] = true;
            }
        }
    }
 
    for (int a, i=0;i<q;++i){
        cin >> a;
        if (a>=maxim ||lucky[a]) cout << "YES\n";
        else cout << "NO\n";
    }
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}