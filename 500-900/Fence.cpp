#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1422/problem/A

typedef long long  ll;

int main(){
    int t;
    cin >> t;
    while (t--){
        int a,b,c;
        cin >> a >> b >> c;
        int maxim = max(a,max(b,c));
        int minim = min(a,min(b,c));
        if (minim==maxim){
            cout << minim << endl;
            continue;
        }
        if (a==b){
            cout << c << endl;
            continue;
        }
        if (b==c){
            cout << a << endl;
            continue;
        }
        if (a==c){
            cout << b << endl;
            continue;
        }
        int third=0;
        if (a!= minim && a!= maxim) third = a;
        if (b!= minim && b!= maxim) third = b;
        if (c!= minim && c!= maxim) third = c;
 
        cout << (int) sqrt(pow((double)(maxim-minim),2) + pow((double)third,2)) << endl;
    }
    return 0;
}