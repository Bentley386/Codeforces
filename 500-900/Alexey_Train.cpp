#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1501/problem/A

typedef long long  ll;
 
#define N 100005
 
 
void solve(){
    int n;
    cin >> n;
    vector<int> a(n),b(n),t(n);
    for (int i=0;i<n;++i){
        cin >> a[i];
        cin >> b[i];
    }
    for (int i=0;i<n;++i){
        cin >> t[i];
    }

    ll time = 0;
    for (int i=0;i<n;++i){
        if (i==0) {
            time+=a[0]+t[0];
            continue;
        }
        int wait =  (b[i-1]-a[i-1])/2 + ((b[i-1]-a[i-1])%2 != 0);
        time+=wait;
        if (time<b[i-1]) time=b[i-1];
        time+=a[i]-b[i-1]+t[i];
    }
    cout << time << "\n";

}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}