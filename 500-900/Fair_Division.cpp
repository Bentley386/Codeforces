#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1472/problem/B

typedef long long  ll;
 
bool solve(){
    int n;
    cin >> n;
    int two=0,one=0;
    for (int in,i=0;i<n;++i){
        scanf("%d",&in);
        if (in == 2) two++;
        else one++;
    }
    two %=2;
    if (two==1 && one<2) return false;
    one-=2;
    if (one%2 == 0) return true;
    return false;
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        if(solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}