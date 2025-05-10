#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1469/problem/A

typedef long long  ll;
 
bool solve(string &s){
    int num = 0;
    bool rdy = false;
    for (char &c : s){
        rdy = false;
        if (c == '?') num++;
        else if (c  == ')') {
            if (num==0) return false;
            num--;
        }
        else if (c == '(') {
            num++;
            rdy = true;
        }
    }
    if (num%2 == 1 || rdy) return false;
    return true;
}
 
int main(){
    int t;
    cin >> t;
    string s;
    getline(cin,s);
    while (t--) {
        getline(cin,s);
        if (solve(s)) cout << "yes";
        else cout << "no";
        cout << "\n";
    }
 
    return 0;
}