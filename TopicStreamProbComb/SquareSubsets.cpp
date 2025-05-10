#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;

// https://codeforces.com/gym/306143/problem/H

typedef long long  ll;
 
#define N 100005
 
int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67}; //length 19
int factors[71]; //prime factorization bitmask for each num
ll dp[(1<<20)][2]; //[factor bitmask][curr or prev]
 
void factorize(int x){
    int y = x;
    int result = 0; //factorization
    for (int i=0;i<19;++i){
        int num = 0;
        while (y%primes[i] == 0) {
            y/= primes[i];
            num++;
        }
        if (num%2 == 1) result |= (1<<i);
    }
    factors[x] = result;
}
 
ll binPow(ll a, ll n) { //a^n
    if (n==0) return 1LL;
    ll result = binPow(a,n/2);
    result = (result * result) % MOD;
    return (n%2 == 0) ? result : (result*a % MOD);
}
 
int main(){
    for (int i=1;i<=70;++i) factorize(i);
 
    int n;
    cin >> n;
 
    unordered_map<int,int> fact;
    for (int temp,i=0;i<n;++i){
        scanf("%d",&temp);
        if (fact.count(factors[temp])) {
            fact[factors[temp]]++;
        }
        else fact[factors[temp]] = 1;
    }
 
    for (auto x : fact){
        int number = x.second; //number of ints with this mask
        int mask = x.first;
        ll numberSq, numberNot;
        if (number == 0) {
            numberSq = 0LL;
            numberNot = 0LL;
        } else {
            numberSq = binPow(2,number-1) - 1;  //in how many ways can we make a square number with i nC2 + nC4 + nC6 
            numberNot = numberSq + 1; //in how many ways non square with i  nC1 + nC3 + nC5 + nC7 +...
        }
        //(1+x)^n = nC0 + nC1 x + nC2 x^2 + ... + nCn x^n,    2^n = nC0 + nC1 + nC2 + ... + nCn
        //(1-x)^n = nC0 - nC1 x + nC2 x^2 - ....,     0 = nC0 - nC1 + nC2 - nC3 + ....
        // 2^n = 2 (nC0 + nC2 + nC4 + ...) ,  nC2 + nC4 + nC6 + ... = 2^(n-1) - 1
        //2^n = 2 (nC1 + nC3 + nC5 + ...) ->   nC1 + nC3 + nC5 + ... = 2^(n-1)
 
        dp[mask][1] += numberNot;
        dp[0][1] += numberSq;
        dp[mask][1] %= MOD; dp[0][1] %= MOD;

        for (int j=0;j<(1<<20);++j){
            dp[j][1] += dp[j][0];
            dp[j][1] += dp[j][0]*(numberSq) % MOD;
            dp[j ^ mask][1] += dp[j][0]*(numberNot) % MOD;
            dp[j][1] %= MOD; dp[j^ mask][1] %= MOD;
        }

        for (int j=0;j<(1<<20);++j) {
            dp[j][0] = dp[j][1];
            dp[j][1] = 0;
        }
    }
    ll result = dp[0][0];
    cout << result << endl;
    return 0;
}