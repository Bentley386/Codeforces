#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1419/problem/B

typedef long long  ll;
 
int main(){
    int t;
    cin >> t;
    while (t--){
        ll x;
        cin >> x;
        ll number=1;
        x-=1;
        int count = 1;
        ll size = 1;
        for (;;){
            size=size+1;
            number = 2*number + size*size;
            if (number>x) break;
            x-=number;
            count++;
            size += size-1;
        }
        cout << count << endl;
    }
    return 0;
}