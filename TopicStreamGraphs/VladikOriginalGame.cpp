#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;

// https://codeforces.com/gym/317667/problem/J

typedef long long  ll;

#define N 105
int n,m;
char grid[N][N];
bool visited[N][N];

vector<char> sol;

bool findSol(int i, int j){
    visited[i][j] = true;
    if (grid[i][j] == 'F') return true;
    if (grid[i][j] == '*') return false;
    if (i<n && !visited[i+1][j]) {
        if (findSol(i+1,j)){
            sol.push_back('D');
            return true;
        }
    }
    if (j<m && !visited[i][j+1]) {
        if (findSol(i,j+1)){
            sol.push_back('R');
            return true;
        }
    }
    if (i>1 && !visited[i-1][j]) {
        if (findSol(i-1,j)){
            sol.push_back('U');
            return true;
        }
    }
    if (j>1 && !visited[i][j-1]) {
        if (findSol(i,j-1)){
            sol.push_back('L');
            return true;
        }
    }
    return false;
}

int main(){
    cin >> n >> m >> ws;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j) scanf("%c",&grid[i][j]);
        if (i!= n) cin >> ws;
    }
    findSol(1,1);
    reverse(sol.begin(),sol.end());

    map<char,char> translate;
    char values[] = {'U','D','L','R'};
    for (char x : values) translate[x] = x;

    bool checkVert=false,checkHor=false;
    int resx,resy;
    for (char c : sol){
        if ( c == 'R' &&  !checkHor){
            checkHor = true;
            cout << "R" << endl;
            cin >> resx >> resy;
            if (resy > 1) {
                continue;
            } else {
                translate['L'] = 'R';
                translate['R'] = 'L';
            }
        }
        if ( c == 'D' &&  !checkVert){
            checkVert = true;
            cout << "D" << endl;
            cin >> resx >> resy;
            if (resx > 1) {
                continue;
            } else {
                translate['U'] = 'D';
                translate['D'] = 'U';
            }
        }
        cout << translate[c] << endl;
        cin >> resx >> resy;
    }
    return 0;
}