#include<bits/stdc++.h>
 
#define INF 1000000005
#define MOD 1000000007
using namespace std;

// https://codeforces.com/contest/1476/problem/D

typedef long long  ll;
 
#define N 5005
 
vector<pair<int,int>> adj[N];
int ind[N][N]; // [curr ind][have visited this many] index of prev
int dp[N][N]; //[end at this vert][have visited this many] min time
int n, m, T;

int main(){
    cin >> n >> m >> T;
    for (int i=0;i<m;++i){
        int u,v,t;
        scanf("%d %d %d",&u, &v, &t);
        adj[u].push_back(make_pair(v,t));
    }

    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j) dp[i][j] = INF;
    }
    dp[1][1] = 0;
    for (auto x : adj[1]){
        dp[x.first][2] = x.second;
        ind[x.first][2] = 1;
    }
    for (int i=3;i<=n;++i){ //how many taken
        for (int j=1;j<=n;++j){ //previous last
            for (auto x : adj[j]) {
                if (dp[j][i-1] + x.second < dp[x.first][i]){
                    dp[x.first][i]= dp[j][i-1] + x.second;
                    ind[x.first][i] = j;
                }
            }
        }
    }
    int result=0;
    for (int i=n;i>=1;--i){
        if (dp[n][i] <= T) {
            result = i;
            break;
        }
    }
    cout << result << endl;
    vector<int> solution(result);
    solution[0]=n;
    for (int i=1;i<=solution.size();++i){
        solution[i] = ind[solution[i-1]][result--];
    }
    for (int i=solution.size()-1;i>=0;--i){
        cout << solution[i] << " ";
    }

}