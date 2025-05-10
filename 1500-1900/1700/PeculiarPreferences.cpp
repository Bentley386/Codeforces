#include<bits/stdc++.h>
 
using namespace std;

// https://codeforces.com/contest/1628/problem/B

using ll = long long;

constexpr ll INF = 2000000000;
constexpr ll MOD = 998244353;
constexpr int N = 100005;

void solve(){
    int n; cin >> n;
    set<string> prefixes3, prefixes2, prefixes32;
    bool found = false;
    for (int i=0;i<n;++i){
        string s;
        getline(cin >> ws, s);
        if (s.size() == 1) found = true;
        else if (s.size() == 2){
            prefixes2.insert(s);
            reverse(s.begin(),s.end());
            if (prefixes2.count(s) || prefixes32.count(s)) found = true;
        } else {
            prefixes3.insert(s);
            prefixes32.insert(s.substr(0,2));
            reverse(s.begin(),s.end());
            if (prefixes2.count(s.substr(0,2)) || prefixes3.count(s)) found = true;
        }
    }

    if (found) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}