#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1428/problem/C

typedef long long  ll;
 
 
int main(){
    int t;
    cin >> t;
    char c;
    scanf("%c",&c);
    while (t--){
        scanf("%c",&c);
        stack<char> s1;
        for (int i=0;c!='\n';++i){
            if(c == 'B' && s1.size() > 0) {
                s1.pop();
            } else {
                s1.push(c);
            }
            scanf("%c",&c);
        } //ABAB
        cout << s1.size() << '\n';
    }
    return 0;
}