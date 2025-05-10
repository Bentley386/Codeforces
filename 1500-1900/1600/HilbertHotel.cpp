#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>
#include<cmath>
#include<unordered_set>

using namespace std;

// https://codeforces.com/contest/1175/problem/B

typedef long long  ll;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0;i<n;i++) cin >> a[i];
        vector<int> counts(n,0);
        for (int i=0;i<n;i++){
            counts[((i+a[i % n]) % n + n)%n]++;
        }
        bool possible=true;
        for (int i=0;i<n;i++) {
            if (counts[i] != 1) possible=false;
        }
        if (possible) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}