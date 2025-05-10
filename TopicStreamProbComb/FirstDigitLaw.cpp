#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/gym/306143/problem/I

typedef long long  ll;

#define N 1005

double probs[N];
double dp[N][N];  //[prob of drawing i correct ones][by the time (inclusive) we draw from jth batch]

int numDigits(ll x){
    int res = 1;
    while (x>=10) {
        x/= 10;
        res++;
    }
    return res;
}

int firstDigit(ll x, int num){
    while (num>1){
        x/=10;
        num--;
    }
    return x;
}

double calcProb(ll L, ll R){
    int numL = numDigits(L); int numR = numDigits(R);
    int firstL = firstDigit(L,numL); int firstR = firstDigit(R,numR);
    if (numL == numR && firstL == firstR && firstL == 1){
        return 1.0;
    }
    ll viable = 0;
    if (firstL == 1){
        if (L==1) viable = 1;
        else {
            ll temp = 1;
            for (int i=0;i<numL-1;++i) temp *= 10;
            temp *= 2;
            viable += temp-L;
        }
    }
    if (firstR == 1) {
        ll temp = 1;
        for (int i=0;i<numR-1;++i) temp*=10;
        viable += R-temp+1; 
        numR--;
    } 
    ll temp=1;
    for (int i=0;i<numL;++i) temp*=10;
    for (int i=numL+1;i<=numR;++i){
        viable += temp;
        temp *= 10;
    }

    return (double) viable / (R-L+1);
}

int main(){
    int n,k;
    cin >> n;
    for (int i=0;i<n;++i){
        ll L,R;
        cin >> L >> R;
        probs[i] = calcProb(L,R);
    }
    cin >> k;
    dp[0][0] = 1.0 - probs[0];
    dp[1][0] = probs[0];
    for (int i=1;i<n;++i){
        for (int j=0;j<=i;++j){
            dp[j][i] += dp[j][i-1]*(1.0-probs[i]);
            dp[j+1][i] += dp[j][i-1]*probs[i];
        }
    }
    int threshold = (n*k % 100 == 0) ? n*k/100 : n*k/100 + 1;
    double result = 0;
    for (int i=threshold;i<=n;++i) result += dp[i][n-1];
    cout << setprecision(15) << result << endl;
    return 0;
}