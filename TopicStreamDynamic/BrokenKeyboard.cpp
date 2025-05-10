#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;

// https://codeforces.com/gym/302977/problem/B

typedef long long  ll;
 
#define N 100005
 

int main(){
    int n,k;
    cin >> n >> k;
    string s;
    getline(cin>>ws,s);
    set<char> allowed;
    for (int i= 0;i<k;++i){
        char c;
        cin >> c;
        allowed.insert(c);
    }
    ll total=0;
    ll current=0; //number of substrings ending at prev
    for (char c : s){
        if (allowed.count(c)){
            current = 1 + current;
            total+=current;
        } else {
            current=0;
        }
    }
    cout << total << endl;
    return 0;
}