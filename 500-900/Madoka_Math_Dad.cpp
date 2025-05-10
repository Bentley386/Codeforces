#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
#define N 200005

using namespace std;

// https://codeforces.com/contest/1647/problem/A

typedef long long  ll;

void solve(){
    int n; cin >> n;
    if (n<3){
        cout << n << endl;
        return;
    }
    if (n%3 == 0){
        for (int i=0;i<n/3;++i) cout << "21";
        cout<< endl;
    } else if (n%3 == 1){
        for (int i=0;i<n/3;++i) cout << "12";
        cout << "1\n";
    } else {
        for (int i=0;i<n/3;++i) cout << "21";
        cout << "2\n";
    }
}

int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
} 