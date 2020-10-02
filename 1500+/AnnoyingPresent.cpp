#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>
#include<cmath>
#include<unordered_set>

#define INF 1000000000
#define MOD 998244353
using namespace std;
typedef long long  ll;
pair<long double,long double> changes[100010];

int main(){
    int n,m;
    cin >> n >> m;
    for (int i=0;i<m;i++) cin >> changes[i].first >> changes[i].second;
    long double sum = 0;
    for (int i=0;i<m;i++){
        pair<long double,long double> x = changes[i];
        long double fulladd = x.first*n + x.second*0.5*n*(n-1);
        long double midadd;
        if (n%2==1) {
            int nn=(n-1)/2;
            midadd = x.first*n + x.second*nn*(nn+1);
        }
        else {
            int nn=n/2;
            midadd = x.first*n + x.second*0.5*nn*(nn+1) + x.second*0.5*(nn-1)*nn;
        }
        sum += max(midadd,fulladd);

    }
    cout << setprecision(numeric_limits<double>::max_digits10) << sum/n;
    return 0;
}