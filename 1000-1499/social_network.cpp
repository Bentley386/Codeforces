#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;
typedef long long int li;


int main(){
    //ifstream input;
    //input.open("test.txt",ios::in);
    int n,k,current;
    cin >> n >> k;
    
    vector<int> convos;
    for(int i=0;i<n;i++) {
        cin >> current;
        if (find(convos.begin(),convos.end(),current) != convos.end()) continue;
        if (convos.size()==k) convos.pop_back();
        convos.insert(convos.begin(),current);
    }
    cout << convos.size() << endl;
    for(int i=0;i<convos.size()-1;i++) cout << convos[i] << " ";
    cout << convos[convos.size()-1] << endl;
    //input.close();
    return 0;
}