#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1469/problem/C

typedef long long  ll;
 
bool solve(const vector<int>& h, int n, int k){
    int mini=h[0],maxi=h[0];
    for (int i=1;i<n-1;++i){
        if (h[i]+2*(k-1) < mini || h[i] > maxi+k-1) return false;
        mini = max(h[i],mini-k+1);
        maxi = min(maxi+k-1,h[i]+k-1);
    }
    if (mini > h[n-1]+k-1 || maxi+k-1 < h[n-1]) return false;
    return true;
}
 
int main(){
    int t,n,k;
    vector<int> h;
    cin >> t;
    while (t--){
        cin >> n >> k;
        h = vector<int>(n);
        for (int i=0;i<n;++i) cin >> h[i];
        if (solve(h,n,k)) cout << "yes";
        else cout << "no";
        cout << endl;
 
    }
    return 0;
}