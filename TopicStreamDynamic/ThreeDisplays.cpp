#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;

// https://codeforces.com/gym/302977/problem/H

typedef long long  ll;
 
#define N 100005

int main(){
    int n;
    cin >> n;
    vector<int> s(n),c(n);
    for (int i=0;i<n;++i) scanf("%d",&s[i]);
    for (int i=0;i<n;++i) scanf("%d",&c[i]);
    vector<int> pairs(n);

    for (int i=1;i<n;++i){
        int minimal = INF;
        for (int j=0;j<i;++j){
            if (s[i]<=s[j]) continue;
            minimal = min(minimal,c[i]+c[j]);
        }
        pairs[i] = minimal;
    }
    int result=INF;
    for (int i=2;i<n;++i){
        for (int j=1;j<i;++j){
            if (s[i] <= s[j]) continue;
            result = min(result,pairs[j]+c[i]);
        }
    }
    if (result == INF) cout << "-1\n";
    else cout << result << endl;
}