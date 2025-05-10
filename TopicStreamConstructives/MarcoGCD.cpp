#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/gym/307122/problem/F

typedef long long  ll;

#define N 1005

int main(){
    int m;
    cin >> m;
    set<int> elements;
    int gcd = 0;
    for (int temp,i=0;i<m;++i){
        scanf("%d",&temp);
        elements.insert(temp);
        gcd = __gcd(gcd,temp);
    }
    if(elements.count(gcd) == 0) {
        cout << "-1";
    }
    else {
        cout << 2*m << endl;
        for (int x : elements){
            cout << x << " ";
            cout << gcd << " ";
        }
    }
    cout << endl;
    return 0;
}