#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/gym/307122/problem/H

typedef long long  ll;

#define N 505
int n;
bool grid[N][N];

void printSol(int i, int j){
    if (i==n){
        if (j==n){
            cout << endl;
            return;
        }
        cout << "R";
        printSol(i,j+1);
    }
    else if (j==n) {
        cout << "D";
        printSol(i+1,j);
    }
    else if (grid[i+1][j]) {
        cout << "D";
        printSol(i+1,j);
    } else {
        cout << "R";
        printSol(i,j+1);
    }
}

bool possible(int i, int j, bool start){
    string answer;
    if (start){
        cout << "? " << i << " " << j << " " << n << " " << n << endl;
    }
    else {
        cout << "? 1 1 " << i << " " << j << endl;
    }
    getline(cin >> ws,answer);
    if (answer == "YES") return true;
    else return false;
}

void fromStart(int i, int j){
    if (i+j == n+1) return;
    if (i==n) {
        grid[i][j+1] = true;
        fromStart(i,j+1);
     } else if (j==n) {
         grid[i+1][j] = true;
         fromStart(i+1,j);
    } else if (possible(i+1,j,true)){
        grid[i+1][j] = true;
        fromStart(i+1,j);
    } else {
        grid[i][j+1] = true;
        fromStart(i,j+1);
    }
}


void fromEnd(int i, int j){
    if (i+j == n+1) return;
    if (i==1){
        grid[i][j-1] = true;
        fromEnd(i,j-1);
    } else if (j==1){
        grid[i-1][j] = true;
        fromEnd(i-1,j);
    } else if (possible(i,j-1,false)){
        grid[i][j-1] = true;
        fromEnd(i,j-1);
    } else {
        grid[i-1][j] = true;
        fromEnd(i-1,j);
    }
}

int main(){
    cin >> n;
    grid[1][1] = true; grid[n][n] = true;
    fromStart(1,1);
    fromEnd(n,n);
    cout << "! ";
    printSol(1,1);
    return 0;
}