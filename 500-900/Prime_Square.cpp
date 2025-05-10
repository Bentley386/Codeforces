#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1436/problem/B

typedef long long  ll;
 
 int sieve[100005];
 
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                if (j==i) cout << "1 ";
                else if (j==(i+1)%n) cout << "1 ";
                else cout << "0 ";
            }
            cout << "\n";
        }
    }
    return 0;
}