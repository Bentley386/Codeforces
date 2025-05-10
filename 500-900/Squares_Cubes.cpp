#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1619/problem/B

typedef long long  ll;

void solve(){
    int n; cin >> n;
    set<int> likes;
    for (int i=1;i*i<=n;++i){
        likes.insert(i*i);
    }
    for (int i=1;i*i*i<=n;++i){
        likes.insert(i*i*i);
    }
    cout << likes.size() << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}