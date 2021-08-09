#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 1000000007
using namespace std;
typedef long long  ll;
 
#define N 1010
int a[N][N];
int b[N][N];
 
bool tryNoHori(int n){
    bool flag[n];
    for (int i=0;i<n;++i){
        if (a[0][i] == b[0][i]) flag[i] = false;
        else flag[i] = true;
    }
    for (int i=1;i<n;++i){
        for (int j=0;j<n;++j){
            if (!flag[j] && a[i][j] != b[i][j]){
                for (int k=0;k<n;++k){
                    if (!flag[k] && a[i][k] == b[i][k]) return false;
                    if (flag[k] && a[i][k] != b[i][k]) return false;
                }
                break;
            }
            if (flag[j] && a[i][j] == b[i][j]){
                for (int k=0;k<n;++k){
                    if (flag[k] && a[i][k] != b[i][k]) return false;
                    if (!flag[k] && a[i][k] == b[i][k]) return false;
                }
                break;
            }
        }
    }
    return true;
}
 
bool tryHori(int n){
    bool flag[n];
    for (int i=0;i<n;++i) a[0][i] = 1 - a[0][i];
 
    for (int i=0;i<n;++i){
        if (a[0][i] == b[0][i]) flag[i] = false;
        else flag[i] = true;
    }
    for (int i=1;i<n;++i){
        for (int j=0;j<n;++j){
            if (!flag[j] && a[i][j] != b[i][j]){
                for (int k=0;k<n;++k){
                    if (!flag[k] && a[i][k] == b[i][k]) return false;
                    if (flag[k] && a[i][k] != b[i][k]) return false;
                }
                break;
            }
            if (flag[j] && a[i][j] == b[i][j]){
                for (int k=0;k<n;++k){
                    if (flag[k] && a[i][k] != b[i][k]) return false;
                    if (!flag[k] && a[i][k] == b[i][k]) return false;
                }
                break;
            }
        }
    }
    return true;
 
}
 
void solve(){
    int n;
    cin >> n;
    cin.ignore();
    string s;
    for (int i=0;i<n;++i){
        getline(cin,s);
        for (int j=0;j<n;++j){
            a[i][j] = (s[j]  == '0') ? 0 : 1;
        }
    }
    getline(cin,s);
    for (int i=0;i<n;++i){
        getline(cin,s);
        for (int j=0;j<n;++j){
            b[i][j] = (s[j]  == '0') ? 0 : 1;
        }
    }
 
    if (tryNoHori(n)) cout << "YES";
    else if (tryHori(n)) cout << "YES";
    else cout << "NO";
    cout << endl;
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}