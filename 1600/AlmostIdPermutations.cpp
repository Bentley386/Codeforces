#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;
typedef long long  ll;
 
#define N 100005

ll choose (ll n, ll k){
    ll result=1;
    for (ll i=0;i<k;++i){
        result*= (n-i);
    }
    ll denom = 1;
    for (ll i=2;i<=k;++i) denom *= i;

    return result/denom;
}

int main(){
    ll n,k;
    cin >> n >> k;
    vector<ll> derang {0,0,1,2,9};
    ll result = 1;
    for (ll i=2;i<=k;++i) {
        result += choose(n,i)*derang[i];
    }
    cout << result << endl;
}