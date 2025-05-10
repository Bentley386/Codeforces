#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>
#include<cmath>
#include<unordered_set>

#define INF 1000000000
using namespace std;

// https://codeforces.com/contest/1269/problem/B

typedef long long  ll;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n),b(n),toTest(n);
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) cin >> b[i];
    sort(b.begin(),b.end());
    int lowest = INF;
    int x;
    for(int i=0;i<n;i++){
        x=(b[0]-a[i] + m) % m;
        for (int j=0;j<n;j++) toTest[j] = (a[j]+x)%m;
        sort(toTest.begin(),toTest.end());
        if (b==toTest && x < lowest) lowest=x; 
    }
    cout << lowest;

    return 0;
}