#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/gym/307122/problem/D

typedef long long  ll;

#define N 1005

int main(){
    int k;
    ll n,s;
    cin >> n >> k >> s;
    if (k>s || s>(n-1)*k) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";

    int i=0;
    for (;;++i){
        if ((s-(n-1))>=k-1) {
            cout << ((i%2 == 0) ? n : 1) << " ";
            s-=n-1;
            k--;
            if (s==0) return 0;
        } else {
            break;
        }
    }
    if (i%2 == 0){
        int j=0;
        for (;j<k-1;++j){
            cout << ((j%2==0) ? 2 : 1) << " ";
            s--;
        }
        cout << j%2+1+s;
    } else {
        int j=0;
        for (;j<k-1;++j){
            cout << ((j%2==0) ? n-1 : n) << " ";
            s--;
        }
        cout << n-j%2 - s;
    }
    return 0;
}