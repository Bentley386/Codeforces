#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1466/problem/C

typedef long long  ll;
 
void solve(){
    string s;
    getline(cin,s);
    int n=s.length();
    int num=0;
    vector<int> toChange(n,0);
    for (int i=0;i<n-1;++i){
        if (i<n-2 && s[i] == s[i+2]){
            if (toChange[i]) continue;
            num++;
            toChange[i+2]=1;
        }
        if (s[i] == s[i+1]) {
            if (toChange[i]) continue;
            num++;
            toChange[i+1]=1;
        }
 
    }
    cout << num << endl;
}
 
int main(){
    int t;
    cin >> t;
    string s;
    getline(cin,s);
    while (t--){
        solve();
    }
    return 0;
}