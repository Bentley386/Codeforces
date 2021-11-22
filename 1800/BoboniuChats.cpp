#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>
#include<cmath>
#include<unordered_set>

#define INF 100000000
#define MOD 998244353
using namespace std;
typedef long long  ll;

int main(){
    int n,d,m;
    cin >> n >> d >> m;
    vector<int> big,small;
    for (int a,i=0;i<n;i++){
        scanf("%d",&a);
        if (a>m) big.push_back(a);
        else small.push_back(a);
    }

    sort(big.begin(),big.end()); 
    sort(small.begin(),small.end());
    vector<ll> smallPrefix(small.size()+1), bigPrefix(big.size()+1);
    smallPrefix[0]=0;
    bigPrefix[0]=0;
    for(int i = 1;i<=small.size();i++) smallPrefix[i] = smallPrefix[i-1] + small[i-1];
    for(int i=1;i<=big.size();i++) bigPrefix[i] = bigPrefix[i-1] + big[i-1];
    if (big.size()==0){
        cout << smallPrefix[small.size()];
        return 0;
    }

    ll best=0;
    ll res;
    int ind2;
    for (int i=1;i<=min((int)big.size(),(n-1)/(d+1)+1);i++){
        ind2 = (int) (n-(ll)(i-1)*(d+1)-1);
        res = bigPrefix[big.size()]-bigPrefix[big.size()-i] + smallPrefix[small.size()]-smallPrefix[small.size()-ind2];
        best = max(best,res);
    }
    cout << best;
    return 0;
}