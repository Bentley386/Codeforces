#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1430/problem/C

typedef long long  ll;
 
 
int main(){
    int t,n;
    cin >> t;
    while (t--){
        cin >> n;
        vector<pair<int,int>> chosen;
        chosen.push_back({n-1,n});
        int result=(n+(n-1)+1)/2;
        for (int i=n-2;i>0;--i){
            chosen.push_back({i,result});
            result = (result+i+1)/2;
        }
        cout << result << "\n";
        for (auto x : chosen){
            cout << x.first << " " << x.second << "\n";
        }
    }
    return 0;
}