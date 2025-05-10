#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1428/problem/B

typedef long long  ll;
 
 
int main(){
    int t,n;
    cin >> t;
    while (t--){
        cin >> n;
        char c;
        scanf("%c",&c);
        bool allright=true, allleft=true;
        vector<bool> a(n,false);
        int count=0;
        for (int i=0;i<n;++i){
            scanf("%c",&c);
            if (allright && c=='<') allright=false;
            if (allleft && c == '>') allleft=false;
            if (c=='-') {
                if (!a[i]) {
                    a[i] = true;
                    count++;
                } if (!a[(i-1+n)%n]){
                    a[(i-1+n)%n] = true;
                    count++;
                }
            }
        }
        if (allright || allleft){
            cout << n << "\n";
            continue;
        }
        cout << count << "\n";
    }
    return 0;
}