#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1487/problem/B

typedef long long  ll;
 
 
void solve(){
    int n,k;
    cin >> n >> k;
    int result;
    if (n%2==0) {
        result = k%n;
    } else {
        int mid = n/2+1;
        int step = n/2;
        if (k<mid) result = k;
        else if (k==mid) result = k+1;
        else {
            result = k+1;
            result += (k-mid)/(step);
            result = result%n;
        }
    }
    result = (result==0) ? n : result;
    cout << result << "\n"; 
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}