#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>
#include<cmath>
#include<unordered_set>

using namespace std;

// https://codeforces.com/contest/1279/problem/D

typedef long long ll;


const int MOD=998244353;
int itemsnum[1000010];
ll inv(int x);
ll modpow(ll x, int y);

int main(){
    int n;
    map<int,vector<int>> kids;
    cin >> n;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        vector<int> kid(k);
        for (int j=0;j<k;j++) {
            cin >> kid[j];
            itemsnum[kid[j]]++;
        }
        kids[i] = kid;
    }
    //ll inver = inv(n);
    ll factor = (ll)n * n % MOD;
    int result=0;
    for (auto const& x : kids){
        for (int const& y : x.second){ //P=1/n*1/x.size * itemsnum[y]/n
            int denom = factor*x.second.size() % MOD;
            result += inv(denom)*itemsnum[y] % MOD;
            //result+= (((inver*inv(x.second.size())) % MOD) * ((inver*itemsnum[y]) % MOD)) % MOD;
            result %= MOD;
        }
    }
    cout << result << endl;
    return 0;
}


ll inv(int x){
    return modpow((ll)x,MOD-2);
}

ll modpow(ll x, int y){
    if (y==0) return 1ll;
    ll p=modpow(x,y/2) % MOD;
    p =p * p % MOD;
    return (y%2==0) ? p : x*p % MOD;
}