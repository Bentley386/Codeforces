#include<bits/stdc++.h>
 
using namespace std;

// https://codeforces.com/contest/1583/problem/C

using ll = long long;

constexpr ll INF = 2000000000;
constexpr ll MOD = 998244353;
constexpr int N = 1000005;

int h[N],p[N];

void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> grid(n);
    for (int i=0;i<n;++i){
        vector<int> row(m);
        string s;
        getline(cin >> ws,s);
        for (int j=0;j<m;++j) {
            if (s[j] == 'X') row[j] = 1; //filled
            else row[j] = 0;
        }
        grid[i] = row;
    }

    for (int i=1;i<m;++i){
        for (int j=0;j<n-1;++j){
            if (grid[j][i] == 1){
                if (grid[j+1][i-1] == 1){
                    h[i] = 1;
                    break;
                }
            }
        }
    }

    for (int i=1;i<m;++i){
        p[i] = p[i-1] + h[i];
    }

    int q; cin >> q;


    for (int i=0;i<q;++i){
        int x1,x2;
        cin >> x1 >> x2;
        if (x1 == x2) {
            cout << "YES\n";
            continue;
        }
        int res = (x1 == 1) ? p[x2-1] : p[x2-1] - p[x1-1];
        if (res == 0) cout << "YES\n";
        else cout << "NO\n";
    }


}

int main(){
    solve();
    return 0;
}