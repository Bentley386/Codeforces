#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
#define N 200005

using namespace std;

// https://codeforces.com/contest/1682/problem/C

typedef long long  ll;


void solve(){
    int n; cin >> n;
    map<int,int> a;
    for (int temp,i=0;i<n;++i) {
        scanf("%d",&temp);
        if (a.count(temp)) a[temp]=2;
        else a[temp]=1;
    }
    int amount=0;
    for (auto x : a){
        amount += x.second;
    }
    cout << amount/2 + (amount%2 == 0 ? 0 : 1) << endl;
}

int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
} 