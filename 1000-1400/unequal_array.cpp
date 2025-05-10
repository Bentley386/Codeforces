#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
#define N 200005

using namespace std;

// https://codeforces.com/contest/1672/problem/C

typedef long long  ll;

int a[200005];
void solve() {
    int n; cin >> n;
    for (int i=0;i<n;++i) scanf("%d",a+i);

    int first =-1;
    for (int i=0;i<n-1;++i){
        if (a[i] == a[i+1]) {
            first = i+1;
            break;
        }
    }
    int last = -1;
    for (int i=n-1;i>0;--i){
        if (a[i] == a[i-1]) {
            last = i-1;
            break;
        }
    }
    if (first == -1 || last == first-1) {
        cout << 0 << endl;
    } else {
        if (first == last) {
            cout << "1\n";
        } else {
            cout << last-first << endl;
        }
    }
}

int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
} 