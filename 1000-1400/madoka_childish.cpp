#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
#define N 200005

using namespace std;

// https://codeforces.com/contest/1647/problem/C

typedef long long  ll;
string a[105];

void solve(){
    int n,m;
    cin >> n >> m;
    for (int i=0;i<n;++i){
        getline(cin >> ws, a[i]);
    }
    if(a[0][0] == '1'){
        cout << "-1\n";
        return;
    }
    int number=0;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if(a[i][j]=='1') number++;
        }
    }
    cout << number << endl;

    for (int i=0;i<n;++i){
        for (int j=m-1;j>0;--j){
            if (a[i][j] == '1'){
                cout << i+1 << " " << j << " " << i+1 << " " << j+1 << '\n';
            }
        }
    }
    for (int i=n-1;i>0;--i){
        if (a[i][0] == '1'){
            cout << i << " 1 " << i+1 << " 1\n"; 
        }
    }
}

int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
} 