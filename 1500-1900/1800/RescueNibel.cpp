#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1420/problem/D

typedef long long  ll;
 
 
ll results[300005];
 
ll inv(ll);
ll pow(ll, ll);
 
int main(){
    ll n,k;
    cin >> n >> k;
    vector<pair<int,int>> events(2*n);
    int num;
    for (int i=0;i<n;i++){
        scanf("%d",&num);
        events[2*i] = make_pair(num,0);
        scanf("%d",&num);
        events[2*i+1] = make_pair(num,1);
    }
    sort(events.begin(),events.end());
    int on = 0;
    results[k] = 1ll;
    ll result=0;
    for (int i=0;i<2*n;i++){
        if (events[i].second == 0) {
            on++;
            if(on==k) result++;
            if(on>k) {
                results[on] = results[on-1]*on % MOD * inv(on-k) % MOD;
                result = (result + ((results[on] - results[on-1]) % MOD + MOD) % MOD) % MOD;
            }
        }
        else on--;
    }
    cout << result % MOD << endl;
    return 0;
}
 
ll inv(ll a){
    return pow(a,(ll) MOD-2) % MOD;
}
ll pow(ll a, ll b){
    if (b==0) return 1ll;
    ll p = pow(a,b/2) % MOD;
    p = p*p%MOD;
    return (b%2==0) ? p : a*p%MOD;
}