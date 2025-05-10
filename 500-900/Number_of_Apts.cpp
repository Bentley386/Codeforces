#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1430/problem/A

typedef long long  ll;
 
 
int main(){
    int t,n;
    cin >> t;
    while (t--){
        cin >> n;
        int seven=0, three=0,five=0;
        while (n>14){
            n-=7; //23, 16, 9
            seven++;
        }
        if (n%7 ==0) seven+= n/7;
        else if (n%5 == 0) five+=n/5;
        else if (n%3 == 0) three+=n/3; 
        else if (n==8) {five=1; three=1;}
        else if (n==11) {five=1; three=2;}
        else if (n==13) {seven++;three=2;}
        else {
            cout << "-1\n";
            continue;
        }
        cout << three << " " << five << " " << seven << "\n";
    }
    return 0;
}