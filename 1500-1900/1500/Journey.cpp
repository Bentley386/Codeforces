#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;
typedef long long  ll;
 
#define N 300005
 
int fw[N][2],bw[N][2];
 
void solve(){
    int n;
    cin >> n;
    cin.ignore(256,'\n');
    string s;
    getline(cin,s);
 
    if (s[0] == 'L'){
        fw[0][0] = 1; //fw[0] -> 2. city
        fw[0][1] = 0;
    } else {
        fw[0][0] = 0;
        fw[0][1] = 1;
    }
    for (int i=1;i<n;++i){
        if (s[i] == 'L'){
            fw[i][0] = 1+fw[i-1][1];
            fw[i][1] = 0;
        } else {
            fw[i][0] = 0;
            fw[i][1] = 1+ fw[i-1][0];
        }
    }
 
    if (s[n-1] == 'R'){
        bw[n-1][0] = 1; //n. city
        bw[n-1][1] = 0;
    } else {
        bw[n-1][0] = 0;
        bw[n-1][1] = 1;
    }
 
    for (int i=n-2;i>=0;--i){
        if (s[i] == 'R'){
            bw[i][0] = 1+bw[i+1][1];
            bw[i][1] = 0;
        } else {
            bw[i][0] = 0;
            bw[i][1] = 1 + bw[i+1][0];
        }
    }
    cout << 1+bw[0][0] << " ";
    for (int i=0;i<n-1;++i){
        cout << 1+fw[i][0]+bw[i+1][0] << " ";
    }
    cout << 1+fw[n-1][0] << endl;
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}