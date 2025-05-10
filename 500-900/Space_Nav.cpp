#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1481/problem/A

typedef long long  ll;
 
#define N 300005
 
int fw[N][2],bw[N][2];
 
void solve(){
    int px,py;
    cin >> px >> py;
    cin.ignore(256,'\n');
    string s;
    getline(cin,s);
    int up=0,down=0,left=0,right=0;
    for (int i=0;i<s.length();++i){
        if (s[i]=='U'){
            up++;
        } else if (s[i] == 'D'){
            down++;
        } else if (s[i] == 'L'){
            left++;
        } else if (s[i]=='R'){
            right++;
        }
    }
    if ((px>=0 && right>=px) || (px<0 && left>=-px)){
        if ((py>=0 && up>=py) || (py<0 && down>=-py)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}