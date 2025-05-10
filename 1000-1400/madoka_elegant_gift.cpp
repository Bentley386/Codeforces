#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
#define N 200005

using namespace std;

// https://codeforces.com/contest/1647/problem/B

typedef long long  ll;
string a[105];

void solve(){
    int n,m;
    cin >> n >> m;
    for (int i=0;i<n;++i){
        getline(cin >> ws, a[i]);
    }
    bool elegant = true;
    for (int i=0;i<n-1;++i){
        for (int j=0;j<m-1;++j){
            int num=0;
            num+=a[i][j]-'0';
            num+=a[i+1][j]-'0';
            num+=a[i][j+1]-'0';
            num+=a[i+1][j+1]-'0';
            if (num==3) elegant=false;
        }
    }
    if (elegant) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
} 