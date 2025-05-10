#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1478/problem/A

typedef long long  ll;
 
 
void solve(){
    int n;
    cin >> n;
    int curr;
    cin >> curr;
    int last;
    int count = 1;
    int maxcount=1;
    for (int i=1;i<n;++i){
        last = curr;
        cin >> curr;
        if (curr==last){
            count++;
            if (count>maxcount) maxcount=count;
        } else {
            count =1;
        }
    }
    cout << maxcount << endl;
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}