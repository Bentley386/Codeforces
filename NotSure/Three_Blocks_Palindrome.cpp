#include<bits/stdc++.h>

#define INF 100000000
#define MOD 998244353

using namespace std;
typedef long long  ll;


int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n), pos[205], occurences[205];
        set<int> numbers;

        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            if (numbers.count(a[i])==0) numbers.insert(a[i]);
            pos[a[i]].push_back(i);
        }
        for (int x : numbers){
            occurences[x] = vector<int>(n);
            occurences[x][0] = (x==a[0]) ? 1 : 0;
        }
        for (int i=1;i<n;i++){
            for (int x : numbers){
                occurences[x][i] = occurences[x][i-1];
                if (x==a[i]) occurences[x][i]++;
            }
        }
        int maxnum=0;
        for (int x : numbers) maxnum = max(maxnum,occurences[x][n-1]);

        int sol=1;
        int leva,desna;
        for(int i=0;i<=maxnum/2;i++){
            for (int x : numbers){
                if (occurences[x][n-1]/2 < i) continue;
                for (int y : numbers){
                    leva = (i==0) ? 0 : pos[x][i-1];
                    desna = (i==0) ? n-1 : pos[x][pos[x].size()-i]-1;
                    sol=max(sol,2*i+occurences[y][desna]-occurences[y][leva]);
                }
            }
        }
        cout << sol << endl;
    }
    
    return 0;
}

