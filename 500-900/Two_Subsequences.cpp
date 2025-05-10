#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;

// https://codeforces.com/contest/1602/problem/A

typedef long long  ll;

#define N 105

void solve(){
    string s;
    getline(cin >> ws,s);
    int minIndex=0;
    char minChar = s[0];
    for (int i=1;i<s.length();++i){
        if (s[i] < minChar){
            minChar = s[i];
            minIndex = i;
        }
    }
    cout << minChar << " ";
    for (int i=0;i<s.length();++i){
        if (i == minIndex) continue;
        else cout << s[i];
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}