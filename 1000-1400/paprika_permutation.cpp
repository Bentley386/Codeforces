#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;

// https://codeforces.com/contest/1617/problem/C

typedef long long  ll;


void solve(){
    int n; cin >> n;
    set<int> already;
    vector<int> a;
    for (int temp,i=0;i<n;++i) {
        scanf("%d",&temp);
        if (temp <= n && !already.count(temp)) already.insert(temp);
        else a.push_back(temp);
    }
    sort(a.begin(),a.end()); //ai -> [1,..,ceil(n/2))
    int count = 0;
    for (int i=n;i>=1;--i){
        if (already.count(i)){
            continue;
        }
        if (i >= a.back()/2 + (a.back()%2 != 0)) {
            cout << "-1\n";
            return;
        }
        a.pop_back();
        count++;
    }
    cout << count << "\n";
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}