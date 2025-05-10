#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;

// https://codeforces.com/contest/803/problem/F

typedef long long  ll;

#define N 100005
int a[N];
int cnt[N]; //how many times a multiple of [i] appears
int mu[N]; //mobius function
int lp[N]; //lowest prime factor

//subset of length 3: sum(i in A) sum(j in A, j!=i) sum(k in A, k!=j!=i) [gcd(i,j,k)=1]
//=sum(i)sum(j)sum(k)sum(d) mu(d) [d|i][d|j][d|k] = sum(d) #of subsets of size 3 that are multiples of d

void getCnt(int x){
    unordered_set<int> divisors;
    for (int i=1;i*i<=x;++i){
        if (x%i == 0){
            divisors.insert(i);
            divisors.insert(x/i);
        }
    }
    for (int z : divisors) cnt[z]++;
}

void sieve(int n){
    vector<int> primes;
    mu[1]=1;
    for (int i=2;i<=n;++i){
        if (lp[i]==0) {
            mu[i] = -1;
            lp[i] = i;
            primes.push_back(i);
        }
        for (int j=0;j<primes.size() && primes[j] <= lp[i] && primes[j]*i <= n;++j){
            if (i % primes[j] == 0) mu[primes[j]*i] = 0;
            else mu[primes[j]*i] = -mu[i];

            lp[primes[j]*i] = primes[j];
        }
    }
}

ll binPow(ll a, ll b){
    if (b==0) return 1LL;
    ll res = binPow(a,b/2);
    res = res * res % MOD;
    return (b % 2 == 0) ? res : (res * a % MOD);
}

int main(){
    int n;
    cin >> n;
    for (int i=0;i<n;++i) scanf("%d",a+i);
    for (int i=0;i<n;++i) getCnt(a[i]);
    int maxEl = *max_element(a,a+n);
    sieve(maxEl);
    ll result=0;
    for (int i=1;i<=maxEl;++i){
        if (mu[i] == 0) continue;
        result += mu[i]*(binPow(2LL,cnt[i])-1);
        result %= MOD;
        if (result < 0) result += MOD;

    }
    cout << result << endl;
    return 0;
}