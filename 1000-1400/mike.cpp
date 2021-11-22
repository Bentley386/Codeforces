#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>

using namespace std;
typedef long long int li;

int main(){
    //ifstream input;
    //input.open("test.txt",ios::in);
    int n,vsota;
    cin >> n;
    vector<int> sweets(n);
    map<int,int> vsote;
    for(int i=0; i<n; i++) cin >> sweets[i];
    for (int i=0; i<n; i++){
        for (int j=i+1;j<n;j++){
            if (i==j) continue;
            vsota = sweets[i]+sweets[j];
            if (vsote.count(vsota)){
                vsote[vsota]++;
            } else {
                vsote[vsota] = 1;
            }
        }
    }
    int maks = 1;
    for (pair<int,int> p : vsote){
        if (p.second > maks) maks = p.second;
    }
    cout << maks << endl;
    return 0;
}