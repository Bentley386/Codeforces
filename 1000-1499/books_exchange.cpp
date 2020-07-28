#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;
typedef long long int li;


int main(){
    //ifstream input;
    //input.open("test.txt",ios::in);
    int q,n;
    int kid,days;
    cin >> q;
    vector<int> perm;
    while (q--){
        cin >> n;
        perm = vector<int>(n);
        for(int i=0;i<n;i++) cin >> perm[i];
        for(int i=0;i<n;i++){
            kid=perm[i];
            days=1;
            while (kid != i+1){
                kid = perm[kid-1];
                days++;
            }
            cout << days << " ";
        }
        cout << "\n";
    }
    //input.close();
    return 0;
}