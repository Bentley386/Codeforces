#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1466/problem/A

typedef long long  ll;
 
void solve(int n){
    vector<int> trees(n);
    for (int i=0;i<n;++i) cin >> trees[i];
    set<int> unique;
    for (int i=0;i<n;++i){
        for (int j=i+1;j<n;++j){
            unique.insert(trees[j]-trees[i]);
        }
    }
    cout << unique.size() << endl;
}
 
int main(){
    int t,n;
    cin >> t;
    while (t--){
        cin >> n;
        solve(n);
    }
    return 0;
}