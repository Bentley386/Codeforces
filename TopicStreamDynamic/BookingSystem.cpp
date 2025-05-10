#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;

// https://codeforces.com/gym/302977/problem/L

typedef long long  ll;
 
#define N 100005

int main(){
    int n,k;
    cin >> n;
    vector<tuple<int,int,int>> people(n);
    for (int x,y,i=0;i<n;++i){
        scanf("%d %d",&x,&y); //size money
        people[i] = make_tuple(y,x,i+1);
    }
    sort(people.rbegin(),people.rend());
    cin >> k;
    vector<tuple<int,int,int>> tables(k);
    for (int t,i=0;i<k;++i) {
        cin >> t;
        tables[i] = make_tuple(t,i+1,0);
    }
    sort(tables.begin(),tables.end());
    int totalRequests = 0;
    int totalMoney = 0;
    vector<pair<int,int>> solution;
    for (int i=0;i<n;++i){
        int money = get<0>(people[i]);
        int size = get<1>(people[i]);
        for (int j=0;j<k;++j){
            if (get<0>(tables[j]) >= size && get<2>(tables[j]) == 0){
                tables[j] = make_tuple(get<0>(tables[j]),get<1>(tables[j]),1);
                totalMoney+=money;
                totalRequests++;
                solution.push_back(make_pair(get<2>(people[i]),get<1>(tables[j])));
                break;
            }
        }
    }

    cout << totalRequests << " " << totalMoney << endl;
    if (solution.size()>0){
        for (pair<int,int> x : solution) cout << x.first << " " << x.second << endl;
    }
}