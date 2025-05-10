#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;

// https://codeforces.com/gym/306143/problem/A

typedef long long  ll;

int a[55][55];

int main(){
    int n,m;
    cin >> n >> m;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            cin >> a[i][j];
        }
    }

    ll result=0;
    for (int i=0;i<n;++i) {//row by row {
        ll num=0;
        for (int j=0;j<m;++j)
            if (a[i][j]) num++;
        
        result += pow(2ll,num) + pow(2ll,m-num) - 2; 
    }

    for (int i=0;i<m;++i){
        ll num=0;
        for (int j=0;j<n;++j) if (a[j][i]) num++;

        result += pow(2ll,num) + pow(2ll,n-num) - 2;
    }

    result -= n*m;
    cout << result << endl;
    return 0;
}