#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1422/problem/B

typedef long long  ll;
 
int main(){
    int t;
    cin >> t;
    while (t--){
        int n,m;
        cin >> n >> m;
        vector<vector<int>> a(n);
        for (int i=0;i<n;++i) {
            a[i] = vector<int>(m);
            for (int j=0;j<m;++j){
                cin >> a[i][j];
            }
        }
        if (n==m && n==1){
            cout << 0 << endl;
            continue;
        }
        ll operations=0;
        vector<int> numbers(4);
        int nn = (n % 2 == 0) ? n : n-1;
        int mm = (m % 2 == 0) ? m : m-1;
        for (int i=0;i<nn/2;++i){
            for (int j=0;j<mm/2;++j){
                numbers = {a[i][j],a[n-i-1][j],a[i][m-j-1],a[n-i-1][m-j-1]};
                sort(numbers.begin(),numbers.end());
                int median = numbers[1];
                for (int num : numbers) operations += abs(median-num);
            }
        }
        if (n%2==1) {
            int middle = n/2;
            for (int j=0;j<mm/2;++j){
                operations += abs(a[middle][j]-a[middle][m-j-1]);
            }
        }
 
        if (m%2==1) {
            int middle = m/2;
            for (int i=0;i<nn/2;++i){
                operations += abs(a[i][middle]-a[n-i-1][middle]);
            }
        }
 
        cout << operations << endl;
    }
 
    return 0;
}