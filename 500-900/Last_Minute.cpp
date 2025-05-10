#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1466/problem/B

typedef long long  ll;
 
void solve(int n){
    vector<int> trees(n);
    for (int i=0;i<n;++i) scanf("%d",&trees[i]);
    sort(trees.rbegin(),trees.rend());
    trees[0]++;
    set<int> used = {trees[0]};
    for (int i=1;i<n;++i){
        if (used.count(trees[i]+1) == 0)
            trees[i]++;
        used.insert(trees[i]); 
    }
    cout << used.size() << endl;
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