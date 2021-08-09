#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;
typedef long long  ll;
 
#define N 100005
 
string adj[1005];
 
void solveSame(int i, int j, int m){
    bool swap = true;
    for (int k=0;k<=m;++k){
        if (swap) cout << i << " ";
        else cout << j << " ";
        swap = !swap;
    }
}
 
void solve(){
    int n,m;
    cin >> n >> m;
    string s;
    getline(cin,s);
    for (int i=0;i<n;++i){
        getline(cin,s);
        //cout << "string:" << s;
        adj[i] = s;
    }
 
    for (int i=0;i<n;++i) {
        for (int j=i+1;j<n;++j){
            if (adj[i][j] == adj[j][i]) {
                cout << "YES\n";
                return solveSame(i+1,j+1,m);
            }
        }
    }
 
    if (m%2 == 1) {
        cout << "YES\n";
        return solveSame(1,2,m);
    }
 
    if (n==2) {
        cout << "NO\n";
        return;
    }  
 
    int first=0, second=-1, third=-1;
    for (int i=2;i<n;++i){
        if (adj[1][i] == adj[0][1]){
            second = 1;
            third = i;
            break;
        }
    }
    if (second == -1){
        if (adj[0][1] != adj[0][2]){
            first = 1;
            second = 0;
            third = 2;
        } else {
            second = 2;
            for (int i=1;i<n;++i){
                if (i==2) continue;
                if (adj[2][i] == adj[0][2]) {
                    third = i;
                    break;
                }
            }
        }
    }
    cout << "YES\n";
    first++;second++;third++;
    if ((m/2)%2 == 0){
        solveSame(second,first,m/2);
        solveSame(third,second,m/2-1);
    }
    else { 
        solveSame(first,second,m/2);
        solveSame(third,second,m/2-1);
    }
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
    return 0;
}