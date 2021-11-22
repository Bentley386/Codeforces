#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;
typedef long long int li;

bool check(vector<int> perm, int n);

int main(){
    //ifstream input;
    //input.open("test.txt",ios::in);
    int q,n;
    vector<int> perm;
    cin >> q;
    while(q--){
        cin >> n;
        perm = vector<int>(n);
        for(int i=0;i<n;i++) cin >> perm[i];
        if(check(perm,n)) {cout << "YES\n"; continue;}
        reverse(perm.begin(),perm.end());
        if(check(perm,n)) cout << "YES\n";
        else cout << "NO\n";
    }
    //input.close();
    return 0;
}

bool check(vector<int>perm, int n){
    for(int i=0;i<n;i++){
        if (perm[(i+1)%n]%n != (perm[i]+1)%n) return false;
    }
    return true;
}