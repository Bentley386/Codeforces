#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;
typedef long long  ll;

#define N 200005
int a[N];

int main(){
    int n;
    cin >> n;
    map<int,int> last;
    for (int i=0;i<n;++i) {
        scanf("%d",a+i);
        last[a[i]] = i;
    }
    ll result = 1;
    int currlast = last[a[0]];
    for (int i=1;i<n;++i){
        if (i>currlast){
            result = result * 2 % MOD;
        }
        currlast = max(currlast,last[a[i]]);
    }

    cout << result << endl;
    return 0;
}