#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1474/problem/A

typedef long long  ll;
 
void solve(){
    int n;
    cin >> n;
    char curr;
    cin >> curr;
    cout << "1";
    int sum=1+(curr-'0');
    for (int i=1;i<n;++i){
        cin >> curr;
        if (1+(curr-'0') == sum){
            sum = curr-'0';
            cout << "0";
        } else {
            sum = 1+(curr-'0');
            cout << "1";
        }
    }
    cout << endl;
}
 
int main(){
    int t;
    cin >> t;
    while (t--)
    solve();
    return 0;
}