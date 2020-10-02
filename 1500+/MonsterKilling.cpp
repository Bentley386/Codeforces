#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>
#include<cmath>
#include<unordered_set>

#define INF 1000000000
#define MOD 998244353
using namespace std;
typedef long long  ll;

int heroes[200005]; //heroes[i] largest power hero with s>=i

int main(){
    int t;
    cin >> t;
    while (t--){
        int n,m;
        cin >> n; 
        vector<int> powers(n);
        for (int i=0;i<n;i++) cin >> powers[i];
        cin >> m; 
        for (int i=0;i<m;i++){
            int p,s; 
            cin >> p >> s;
            if (p > heroes[s-1]) heroes[s-1] = p;
        }
        int maxim=0;
        for (int i=n-1;i>=0;i--){ 
            if (heroes[i] != 0){
                maxim = max(maxim,heroes[i]);
            }
            heroes[i] = maxim;

        }
        int days = 1, num=0,maxpower=0; 
        for (int i=0;i<n;i++){
            if (powers[i] > heroes[0]) {days=-1;break;}
            if (heroes[num] >= powers[i] && heroes[num] >= maxpower) {num++; maxpower=max(maxpower,powers[i]);}
            else {
                days++;
                num=1;
                maxpower=powers[i];
            }
        }
        cout  << days << endl;
        for (int i =0;i<n;i++) heroes[i]=0;
    }
    return 0;
}