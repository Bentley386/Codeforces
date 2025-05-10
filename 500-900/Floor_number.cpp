#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1426/problem/A

typedef long long  ll;
 
int main(){
    int t,n,x;
    cin >> t;
    while (t--){
        cin >> n >> x;
        int floor=1;
        if (n<3) {
            cout << "1\n";
            continue;
        }
        int end=2;
        for(;;){
            if (n>end && n<=floor*x+2){
                cout << ++floor << endl;
                break;
            }
            end=floor*x+2;
            floor++;
        }
    }
    return 0;
}