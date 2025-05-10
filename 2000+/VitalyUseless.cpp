#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
#define N 200005

using namespace std;

// https://codeforces.com/contest/1650/problem/F

typedef long long  ll;

int a[N];
vector<pair<int,int>> trainings[N];
vector<int> mapping[N];
ll dp[201]; //minimum time to get percent [1] using first [2]
int best[201][N];

void populateDP(int k){
    vector<pair<int,int>> options = trainings[k];

    for (int i=1;i<201;++i) {
        for (int j=0;j<(int)options.size();++j){
            dp[i] = INF;
            best[i][j] = -1;
        }
    }
    for (int j=0;j<(int)options.size();++j){
        dp[0] = 0;
        best[0][j] = -1;
    }

    dp[options[0].second] = options[0].first; 
    best[options[0].second][0] = 0; 
    for (int j=1;j<(int) options.size();++j){
        int perc = options[j].second; 
        int time = options[j].first;
        for (int i=200;i>=0;--i){
            if (i<perc) {
                dp[i] = dp[i];
                best[i][j] = -1;
                continue;
            }
            if (dp[i-perc]+time < dp[i]){
                dp[i] = dp[i-perc]+time;
                best[i][j] = j;
            } else {
                dp[i] = dp[i];
                best[i][j] = -1;
            }
        }
    }
}

void solve(){
    int n,m;
    cin >> n >> m;
    for (int i=0;i<n;++i){
        scanf("%d",a+i);
        trainings[i] = vector<pair<int,int>>();
        mapping[i] = vector<int>();
    }
    for (int i=0;i<m;++i) {
        int e,t,p;
        scanf("%d %d %d",&e,&t,&p);
        trainings[e-1].push_back(make_pair(t,p));
        mapping[e-1].push_back(i);
    }
    //minimize time to get total p at least 100;
    ll availabletime = 0;
    vector<int> choices;
    for (int i=0;i<n;++i){
        if (trainings[i].size() == 0) {
            cout << "-1\n";
            return;
        }
        availabletime += (i==0) ? a[i] : a[i]-a[i-1];
        populateDP(i);

        int j=trainings[i].size()-1;
        int bestperc=100;
        ll bestval = dp[100];
        for (int k=101;k<=200;++k){
            if (dp[k] < bestval){
                bestval = dp[k];
                bestperc = k;
            }
        }
        availabletime -= bestval;
        if (availabletime < 0 || bestval == INF) {
            cout << "-1\n";
            return;
        }
        for(;j>=0;--j){
            int cand = best[bestperc][j];
            if (cand == -1) continue;
            choices.push_back(mapping[i][cand]);
            bestperc -= trainings[i][cand].second;
        }
    }
    cout << choices.size() << endl;
    for (int x : choices) cout << x+1 << " ";
    cout << endl;
}

int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
} 