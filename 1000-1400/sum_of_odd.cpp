#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

// https://codeforces.com/contest/1327/problem/A

typedef long long int li;

int main(){
    //ifstream input;
    //input.open("test.txt",ios::in);
    int t, n, k;
    li suma;
    cin >> t;
    mainloop:while (t--){
        cin >> n >> k;
        if (n%2 != k%2) {
            cout << "NO\n";
            continue;
        }
        suma=0;
        for (int i=0;i<k;i++){
            suma += 2*i+1;
            if (suma > n){
                cout << "NO\n";
                goto mainloop;
            }
        }
        cout << "YES\n";
    }
    //input.close();  
    return 0;
}