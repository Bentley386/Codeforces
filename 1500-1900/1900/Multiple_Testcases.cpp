#include<bits/stdc++.h>

#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1342/problem/D

typedef long long  ll;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> ms(n);
    for(int i=0;i<n;++i) scanf("%d",&ms[i]);
    vector<int> c(k+1);
    for(int i=1;i<=k;++i) scanf("%d",&c[i]);
    vector<vector<int>> solution(2);
    sort(ms.rbegin(),ms.rend());
    int test=0;
    for (int m : ms){
        if (solution[test].size() < c[m]){
            solution[test].push_back(m);
            continue;
        }
        test = (test+1) % solution.size();
        if (solution[test].size() < c[m]){
            solution[test].push_back(m);
        } else {
            solution.push_back({m});
            test=solution.size()-1;
        }
    }
    if (solution[1].size()==0) {
        cout << 1 << endl;
    } else {
        cout << solution.size() << endl;
    }
    for (auto x : solution) {
        if (x.size() == 0) continue;
        cout << x.size() << " ";
        for (int y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }
    return 0;
}