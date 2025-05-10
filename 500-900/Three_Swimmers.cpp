#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1492/problem/A

typedef long long  ll;
 


void solve() {
    ll p,a,b,c;
    cin >> p >> a >> b >> c;
    ll timea = (p%a == 0ll) ? 0 : (p/a+1)*a-p;
    ll timeb = (p%b == 0ll) ? 0 : (p/b+1)*b-p;
    ll timec = (p%c == 0ll) ? 0 : (p/c+1)*c-p;
    cout << min(min(timea,timeb),timec) << "\n";
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}