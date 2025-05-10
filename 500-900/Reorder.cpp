#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1436/problem/A

typedef long long  ll;
 
 
int main(){
    int t;
    cin >> t;
    while (t--){
        int n,m;
        cin >> n >> m;
        int sum=0,x;
        for (int i=0;i<n;++i){
            cin >> x;
            sum+=x;
        }
        if (sum==m){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}