#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1492/problem/C

typedef long long  ll;
 
 
void solve(){
    int n,m; // 5 2 ababa, ab
    cin >> n >> m;
    string s,t;
    getline(cin >> ws,s);
    getline(cin >> ws,t);
    vector<int> earliest(m),latest(m);
    int j=0;
    for (int i=0;i<n;++i){
        if (s[i]==t[j]) {
            earliest[j] = i;
            j++;
            if (j==m) break;
        }
    }
    j=m-1;
    for (int i=n-1;i>=0;--i){
        if (s[i]==t[j]){
            latest[j] = i;
            j--;
            if (j<0) break;
        }
    }
    //cout << "a: " << earliest[0] << " " << latest[0] << "\n";
    //cout << "b: " << earliest[1] << " " << latest[1] << "\n";
    int maxim = 1;
    for (int i=0;i<m-1;++i){
        maxim=max(maxim,latest[i+1]-earliest[i]);
    }

    cout << maxim << "\n";

}
 
int main(){
    int t=1;
    //cin >> t;
    while (t--){
        solve();
    }
    return 0;
}