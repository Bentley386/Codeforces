#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/gym/306143/problem/D

typedef long long  ll;

#define N 100005

double ps[N];

double calcProb(int p, int l, int r){
    int range = r-l+1;
    int lower = l/p * p;
    if (lower<l) lower+=p;
    int upper = r/p * p;
    if (lower>upper) return 0.0;
    int valid = (upper-lower)/p + 1;
    return (double) valid / range;
}

int main(){
    int n, p;
    cin >> n >> p;
    for (int i=0;i<n;++i){
        int l,r;
        scanf("%d %d",&l,&r);
        ps[i] = calcProb(p,l,r);
    }
    double result = 0;
    for (int i=0;i<n;++i){
        double prev = (i==0) ? ps[n-1] : ps[i-1];
        double curr = ps[i];
        double next = ps[(i+1)%n];
        result += curr*2000 + (1-curr)*(prev+next)*1000;
    }

    cout << setprecision(15) << result << endl;
    return 0;
}