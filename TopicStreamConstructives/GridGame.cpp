#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/gym/307122/problem/C

typedef long long  ll;

#define N 1005

int main(){
    string s;
    getline(cin, s);
    int vInd = 0, hInd = 1;
    for (int i=0;i<s.length();++i){
        if (s[i] == '0'){
            cout << ((vInd == 0) ? "1 " : "3 ");
            cout << "1\n";
            vInd = (vInd + 1) % 2; 
        } else if (s[i] == '1'){
            cout << hInd << " 3\n";
            hInd++;
            if (hInd==5) hInd = 1;
        }
    }
    return 0;
}