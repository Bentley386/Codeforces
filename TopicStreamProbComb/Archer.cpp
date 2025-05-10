#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;

// https://codeforces.com/gym/306143/problem/B

typedef long long  ll;


int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    double probA = (double) a / b; //0.5
    double probB = (double) c / d; //0.5
    double q = (1-probA)*(1-probB);
    cout << setprecision(15) << probA/(1-q); 

    return 0;
}