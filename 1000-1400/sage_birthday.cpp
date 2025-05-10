#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1419/problem/D1

typedef long long  ll;
 
int main(){
    int n;
    cin >> n;
    vector<int> a(n),order(n);
    for (int i = 0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
 
    order[n-1] = a.back();
    a.pop_back();
 
    for (int i=0;i<n-1;i+=2){
        order[i] = a.back();
        a.pop_back();
    }
 
    for (int i=1;i<n-1;i+=2){
        order[i] = a.back();
        a.pop_back();
    }
    int count=0;
    for (int i=1;i<n-1;i++){
        if (order[i] < order[i+1] && order[i] < order[i-1]) count++;
    }
 
    cout << count << endl;
    for (int i = 0;i<n-1;i++) cout << order[i] << " ";
    cout << order[n-1];
    return 0;
}