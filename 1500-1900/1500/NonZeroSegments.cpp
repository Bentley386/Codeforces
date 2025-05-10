#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1426/problem/D

typedef long long  ll;
 
int a[200005];
ll prefix[200005];
 
int main(){
    int n;
    cin  >> n;
    for (int i=0;i<n;i++) scanf("%d", a+i);
    prefix[0]= (ll) a[0];
    for (int i=1;i<n;i++) prefix[i] = prefix[i-1] + (ll)a[i];
    int count=0;
    set<ll> prefixes = {0};
    for (int i=0;i<n;i++){
        if (prefixes.count(prefix[i])>0){
            count++;
            prefixes = set<ll>();
        } 
        if(i>0) prefixes.insert(prefix[i-1]);
    }
    cout << count;
    return 0;
}
//-1 -1 1 -1 -1
//-1 -2 -1 -2 -3