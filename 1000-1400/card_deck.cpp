#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1492/problem/B

typedef long long  ll;
 
 
void solve(){
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i=0;i<n;++i) scanf("%d",&p[i]);
    reverse(p.begin(),p.end());
    set<int> all;
    for (int i=1;i<=n;++i) all.insert(i);
    stack<int> s;
    for (int i=0;i<n;++i){
        s.push(p[i]);
        if (p[i] == *(--all.end())) {
            while (!s.empty()) {
                cout << s.top() << " ";
                s.pop();
            }
        }
        all.erase(p[i]);
    }
    cout << "\n";


}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}