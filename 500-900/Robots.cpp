#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
#define N 5005

using namespace std;

// https://codeforces.com/contest/1680/problem/B

typedef long long  ll;

bool a[N][N];

void solve(){
    int n,m;
    cin >> n >> m;
    int lowestx = m-1, lowesty = n-1;
    for (int i=0;i<n;++i){
        string s;
        getline(cin >> ws,s);
        for (int j=0;j<m;++j){
            if (s[j] == 'E') a[i][j] = false;
            else {
                a[i][j] = true;
                lowestx = min(lowestx,j);
                lowesty = min(lowesty,i);
            }
        }
    }
    bool found = false;
    for (int i=0;i<=lowesty;++i){
        for (int j = 0;j<=lowestx;++j){
            if (a[i][j]) found = true;
        }
    }
    if (found) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
} 