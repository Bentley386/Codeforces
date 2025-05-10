#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1420/problem/B

typedef long long  ll;
 
int main(){
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> a(n);
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        vector<int> numbers(32,0);
        for (int i=0;i<n;i++){
            numbers[32-__builtin_clz(a[i])]++;
        }
        ll result=0;
        for (int x : numbers){
            result += (ll)x*(x-1)/2;
        }
        cout << result << endl;
    }
    return 0;
}