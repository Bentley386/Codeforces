#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1428/problem/A

typedef long long  ll;
 
 
int main(){
    int t;
    int x1,y1,x2,y2;
    cin >> t;
    while (t--){
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1==x2) cout << abs(y1-y2) << "\n";
        else if (y1 == y2) cout << abs(x1-x2) << "\n";
        else {
            cout << abs(x1-x2) + abs(y1-y2)+2 << "\n";
        }
    }
    return 0;
}