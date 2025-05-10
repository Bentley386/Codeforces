#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;

// https://codeforces.com/gym/302977/problem/I

typedef long long  ll;
 
#define N 100005
int bears[505][505];
int scores[505];


int calcScore(int i,int m){
    int maxscore=0;
    int currscore=0;
    for (int j=0;j<m;++j){
        if (bears[i][j] == 1) currscore++;
        else currscore=0;
        maxscore = max(maxscore,currscore);
    }
    return maxscore;
}

int main(){
    int n,m,q;
    cin >> n >> m >> q;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            scanf("%d",&bears[i][j]);
        }
    }
    for (int i=0;i<n;++i){
        scores[i] = calcScore(i,m);
    }
    for (int k=0;k<q;++k){
        int i,j;
        cin >> i >> j;
        bears[i-1][j-1] = 1 - bears[i-1][j-1];
        scores[i-1] = calcScore(i-1,m);
        cout << *max_element(scores,scores+n) << endl;
    }
}