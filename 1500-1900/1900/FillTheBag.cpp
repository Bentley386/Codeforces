#include<bits/stdc++.h>

#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1303/problem/D

typedef long long  ll;

int main(){
    ll n;
    int t,m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        ll sum=0;
        vector<int> positions(65,0);
        for (int curr,i = 0;i<m;i++){
            scanf("%d",&curr);
            sum+=curr;
            positions[__builtin_ctz(curr)]++;
        }

        if (sum<n) {
            cout << -1 << endl;
            continue;
        }
        int operations=0;
        for (int i=0;i<64;i++){
            //cout << "i: " << i << " operations: " << operations << endl;
            if (positions[i]<0){
                if(positions[i] % 2 == 0){
                    positions[i]=0;
                    positions[i+1] += positions[i]/2;
                    operations += abs(positions[i]/2);
                } else {
                    positions[i]=1;
                    positions[i+1] += positions[i]/2 - 1;
                    operations += abs(positions[i]/2) + 1;
                }
            }
            if(((ll)1<<i & n) == 0){
                positions[i+1]+= (positions[i]>0) ? positions[i]/2 : 0;
            } else {
                if (positions[i]<=0){
                    positions[i+1]--;
                    positions[i]+=2;
                    operations++;
                } else if (positions[i]>2){
                    positions[i+1] += (positions[i]-1)/2;
                }
            }
        }

        cout << operations << endl;

    }
    return 0;
}