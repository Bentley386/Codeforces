#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>
#include<cmath>
#include<unordered_set>

using namespace std;

// https://codeforces.com/contest/1338/problem/A

typedef long long  ll;

int main(){
    //ifstream input;
    //input.open("test.txt",ios::in);
    //4
    //2 -1 -3 -4  
    // dam 4 pravilno 3
    int t,n,T,k;
    vector<int> a;
    cin >> t;
    while (t--){
        T=0;
        cin >> n;
        a = vector<int>(n);
        for(int i=0;i<n;i++) cin >> a[i];
        if (n==1) {cout << 0 << endl; continue;}
        for (int i=1;i<n;i++){
            k=0;
            while(a[i]<a[i-1]){
                a[i] += pow(2,k);
                k++;
            }
            T = max(T,k);
            while (k--){
                if(a[i] - pow(2,k) >= a[i-1]) a[i] -= pow(2,k);
            }
        }
    cout << T << endl;
    }
    return 0;
}