#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1472/problem/A

typedef long long  ll;
 
bool solve(){
    int w,h,n;
    cin >> w >> h >> n;
    int countw=0,counth=0;
    for (;w%2==0;w/=2) countw++;
    for (;h%2==0;h/=2) counth++;
    if (pow(2,countw)*pow(2,counth) >= n) return true;
    else return false;
    
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        if(solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}