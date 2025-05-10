#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

// https://codeforces.com/contest/1333/problem/B

typedef long long int li;

int main(){
    //ifstream input;
    //input.open("test.txt",ios::in);
    int t,n,current;
    vector<int> a;
    bool yes;
    int prvaenka, prvaminus;
    cin >> t;
    while (t--){
        cin >> n;
        yes = true;
        a = vector<int>(n);
        prvaenka = n;
        prvaminus = n;
        for (int i=0;i<n;i++) {
            cin >> a[i];
            if (a[i]== 1 && prvaenka == n) prvaenka = i;
            else if (a[i] == -1 && prvaminus == n) prvaminus = i;
        }
        for (int i=0;i<n;i++){
            cin >> current;
            if (i==0){
                if (a[i] != current) yes = false;
            } else {
                if (a[i] > current){
                    if ( prvaminus < i) continue;
                    else yes = false;
                }
                else if (a[i] < current){
                    if (prvaenka < i) continue;
                    else yes = false;
                }
            }

        }
        if (yes) cout << "YES\n";
        else cout << "NO\n";
    }
    //input.close();  
    return 0;
}