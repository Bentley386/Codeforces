#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/gym/307122/problem/E

typedef long long  ll;

#define N 1005
int rows=0;

void printFill(char first, char second, int num){
    for (int i=0;num!=0;++i){
        if (i%2==0){
            for (int j=0;j<50;++j){
                if (j%2==0 || num==0) cout << first;
                else {
                    cout << second;
                    num--;
                }
            }
        } else {
            for (int j=0;j<50;++j) cout << first;
        }
        cout << '\n';
        rows++;
    }
}

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << "50 50\n";
    printFill('A','B',b); //8
    printFill('A','C',c); //8
    printFill('A','D',d-1); //8
    for (int i=0;i<50;++i) cout << 'A'; //1
    rows++;
    cout << '\n';
    for (int i=0;i<50;++i) cout << 'D'; //1
    rows++;
    cout << '\n';
    printFill('D','A',a-1); //8
    while(rows<50){
        for (int j=0;j<50;++j) cout << 'D';
        cout << '\n';
        rows++;
    }
    return 0;
}