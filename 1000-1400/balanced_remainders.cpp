#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1490/problem/B

typedef long long  ll;
 
 
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> count(3,0);
    for (int i=0;i<n;++i) {
        cin >> a[i];
        a[i] %= 3;
        count[a[i]]++;
    }
    int moves=0;
    if (count[0] > n/3) count[1]+= count[0]-n/3;
    else count[2] -= n/3-count[0];
    moves+=abs(count[0]-n/3);
    count[0]=n/3;
    if (count[1] > n/3) count[2]+= count[1]-n/3;
    else count[0] -= n/3-count[1];
    moves+=abs(count[1]-n/3);
    count[1]=n/3;
    moves+= abs(count[2]-n/3);
 
    cout << moves << endl;
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}