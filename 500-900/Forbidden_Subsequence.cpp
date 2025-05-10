#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;

// https://codeforces.com/contest/1617/problem/A

typedef long long  ll;

void solve(){
    string s,t;
    getline(cin >> ws, s);
    sort(s.begin(),s.end());    
    getline(cin, t);
    if (t != "abc"){
        cout << s;
    } else {
        map<char,int> letters;
        for (char x : s){
            if (letters.count(x)) letters[x]++;
            else letters[x] = 1;
        }
        if (letters.count('a') && letters.count('b') && letters.count('c')){
            for (int i=0;i<letters['a'];++i) cout << 'a';
            for (int i=0;i<letters['c'];++i) cout << 'c';
            for (int i=0;i<letters['b'];++i) cout << 'b';
            for (int i='d';i<='z';++i){
                if (letters.count((char)i)){
                    for (int j=0;j<letters[(char)i];++j) cout << (char) i;
                }
            }
        } else cout << s;
    }
    cout << endl;
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}