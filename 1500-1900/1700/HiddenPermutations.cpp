#include<bits/stdc++.h>
 
using namespace std;

// https://codeforces.com/contest/1621/problem/C

using ll = long long;

constexpr ll INF = 2000000000;
constexpr ll MOD = 998244353;
constexpr int N = 50000;

int p[N];

int ask(int x){
    cout << "? " << x << endl;
    int r; cin >> r;
    return r;
}
void solve(){
    int n; cin >> n;
    if (n==1){
        cout << "! 1\n";
        return;
    }
    int curr;
    curr = ask(1);
    set<int> visited;
    vector<vector<int>> cycles;
    for (int i=1;i<=n;++i) {
        if (visited.count(i) == 0) {
            vector<int> currcycle;
            if (i==n){
                currcycle.push_back(i);
                cycles.push_back(currcycle);
                break;
            }
            while (true){
                curr = ask(i);
                if (visited.count(curr)) break;
                else {
                    visited.insert(curr);
                    currcycle.push_back(curr);
                }
            } cycles.push_back(currcycle);
        }
    }

    for (auto& cycle : cycles){
        int nn = cycle.size();
        for (int i=0;i<nn;++i){
            if (i==nn-1) {
                p[cycle[i]] = cycle[0];
            } else {
                p[cycle[i]] = cycle[i+1];
            }
        }
    }
    cout << "! ";
    for (int i=1;i<=n;++i) cout << p[i] << " ";
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}