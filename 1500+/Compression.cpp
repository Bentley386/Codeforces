#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>
#include<cmath>
#include<unordered_set>

#define INF 100000000
#define MOD 998244353
#define N 6000

bool matr[N][N];

using namespace std;
typedef long long  ll;

int gcd(int a, int b);

int main(){
    int n;
    cin >> n;
    char c;
    int number;
    for (int i=0;i<n;i++){
        scanf("%c",&c);
        for(int j=0;j<n/4;j++){
            scanf("%c",&c);
            number = (c >= 'A') ? 10 + c-'A' : c- '0';
            for (int k=0;k<4;k++){
                matr[i][4*j+k] = ((number & (1<<k)) != 0);
            }
        }
    }
    int solution=n,count;
    for (int i=0;i<n;i++){
        count=1;
        for (int j=1; j<n;j++){
            if (matr[i][j] == matr[i][j-1]) count++;
            else {
                solution = gcd(solution,count);
                count=1;
            }
        }
        solution = gcd(solution,count);
    }

    for (int i=0;i<n;i++){
        count=1;  
        for (int j=1; j<n;j++){
            if (matr[j][i] == matr[j-1][i]) count++;
            else {
                solution=gcd(solution,count);
                count=1;
            }
        }
        solution = gcd(solution,count);
    }
    cout << solution;
    return 0;
}

int gcd(int a, int b){
    if (b>a) swap(a,b);
    if (b==0) return a;
    else return gcd(b,a%b);
}