#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;
typedef long long  ll;

int main(){
    int n, t;
    double p;
    cin >> n >> p >> t;
    double result = p;
    for (int i=2;i<=t;++i){
        result = (1.0-p)*result + p*min((double) n,result+1.0); //E(t) = (1-p)E(t-1) + p(E(t-1)+1)
        result = min((double) n, result);
    }
    cout << setprecision(15) << result << endl;
    return 0;
}