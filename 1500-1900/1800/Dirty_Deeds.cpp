#include<bits/stdc++.h>


#define INF 100000000
#define MOD 998244353

using namespace std;

// https://codeforces.com/contest/1148/problem/D

typedef long long  ll;

int positions[600010];

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> pairs1,pairs2;
    int a,b;
    for (int i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        if (a<b) pairs1.push_back(make_pair(a,b));
        else pairs2.push_back(make_pair(a,b));
        positions[a]=i+1;
    }
    if (pairs1.size()<pairs2.size()){
        sort(pairs2.begin(),pairs2.end());
        cout << pairs2.size() << endl;
        for(auto x : pairs2){
            cout << positions[x.first] << " ";
        }
    } else {
        sort(pairs1.rbegin(),pairs1.rend());
        cout << pairs1.size() << endl;
        for (auto x : pairs1){
            cout << positions[x.first] << " ";
        }
    }
    return 0;
}

