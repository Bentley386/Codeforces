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

using namespace std;

// https://codeforces.com/contest/979/problem/B

typedef long long  ll;


int main(){
    int n;
    cin >> n;
    char c;
    scanf("%c",&c);
    vector<int> dogs[3];
    int count=0;
    for (int i=0;i<3;i++) {
        dogs[i] = vector<int>('z'+5,0);
        for(;;){
            scanf("%c",&c);
            if(c=='\n') break;
            dogs[i][int(c)]++;
            count++;
        }
    }
    int length=count/3;
    int beauty[3];
    for (int i=0;i<3;i++){
        int maxi = *max_element(dogs[i].begin(),dogs[i].end());
        if (maxi==length && n==1) beauty[i]=length-1;
        else beauty[i] = min(maxi+n,length);
    }
    int winner = max_element(beauty,beauty+3)-beauty;
    count=0;
    for (int x : beauty) if (x==beauty[winner]) count++;
    if (count>1) cout << "Draw";
    else{
        if (winner==0) cout << "Kuro";
        else if (winner==1) cout << "Shiro";
        else cout << "Katie";
    }
    return 0;
}

