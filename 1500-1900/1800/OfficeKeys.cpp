#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;
typedef long long  ll;
 
#define N 100005
 
int main(){
    int n,k,p;
    cin >> n >> k >> p;
    vector<int> a(n),b(k);
    for (int i=0;i<n;++i) scanf("%d",&a[i]);
    for (int i=0;i<k;++i) scanf("%d",&b[i]);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int minresult=INF;
    for (int i=0;i<k-n+1;++i){
        int maxresult=-1;
        for (int j=0;j<n;++j){
            maxresult=max(maxresult,abs(a[j]-b[j+i]) + abs(b[j+i]-p));
        }
        minresult = min(minresult,maxresult);
    }
    cout << minresult << endl;

}