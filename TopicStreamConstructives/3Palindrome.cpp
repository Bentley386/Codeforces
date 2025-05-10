#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/gym/307122/problem/A

typedef long long  ll;

#define N 1005

int main(){
    int n;
    cin >> n;
    for (int i=0;i<n;++i){
        if (i%4 < 2) cout << "a";
        else cout << "b";
    }
    return 0;
}