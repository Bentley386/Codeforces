#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1480/problem/B

typedef long long  ll;
 
#define N 100005
 
ll a[N],b[N];
 
void solve(){
    ll A,B,n;
    cin >> A >> B >> n;
    vector<pair<ll,ll>> monster = vector<pair<ll,ll>>();
    for (int i=0;i<n;++i) scanf("%d", a+i);
    for (int i=0;i<n;++i) scanf("%d", b+i);
    for (int i=0;i<n;++i) monster.push_back(make_pair(a[i],b[i]));
    sort(monster.begin(),monster.end());
    for (int i=0;i<n;++i){
        ll a = monster[i].first;
        ll b = monster[i].second;
        ll num = (b % A == 0) ? b/A : b/A+1;
        B -= (num-1)*a;
        if (B<1) {
            cout << "NO\n";
            return;
        } 
        B-= a;
    }
    cout << "YES\n";
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}