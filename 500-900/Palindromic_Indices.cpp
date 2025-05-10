#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
#define N 200005

using namespace std;

// https://codeforces.com/contest/1682/problem/A

typedef long long  ll;

void solve(){
    int n; cin >> n;
    string s;
    getline(cin >> ws,s);
    int mid = n/2;
    int left = 0, right=0;
    for (int i=mid-1;i>=0;--i){
        if (s[i] != s[mid]) break;
        left++;
    }
    for (int i=mid+1;i<n;++i){
        if (s[i]!=s[mid]) break;
        right++;
    }
    if (n%2 == 0) cout << 2+ 2*min(left-1,right) << endl;
    else cout << 1+ 2*min(left,right) << endl;

}

int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
} 