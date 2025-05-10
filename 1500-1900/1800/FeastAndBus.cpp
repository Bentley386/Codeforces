#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>
#include<cmath>
#include<unordered_set>

#define INF 1000000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1250/problem/B

typedef long long  ll;

int main(){
    int n,k,current;
    cin >> n >> k;
    vector<int> teams(k);

    for (int i=0;i<n;i++){
        scanf("%d",&current);
        teams[current-1]++;
    }
    sort(teams.begin(),teams.end());
    ll rent=INF;
    for (int i=0;i<=k/2;i++){
        int capac=0,rides=0;
        for (int j = 0;j<i;j++){
            capac = max(capac,teams[j]+teams[2*i-1-j]);
            rides++;
        }
        for (int j=2*i;j<k;j++){
            capac = max(capac,teams[j]);
            rides++;
        }
        rent = min(rent,(ll)capac*rides);
    }
    cout << rent;
    return 0;
}