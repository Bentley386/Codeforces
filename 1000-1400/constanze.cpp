#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>

using namespace std;
typedef long long  ll;

int main(){
    //ifstream input;
    //input.open("test.txt",ios::in);
    string msg;
    getline(cin,msg);
    int mod = 1e9+7;
    int n = msg.size();
    int first=1;
    int temp;
    int second=1;
    if(msg.find('m') != string::npos || msg.find('w') != string::npos){
        cout << 0 << endl;
        return 0;
    }
    for (int i=1;i<n;i++){
        if ((msg[i]=='n' && msg[i-1]=='n') || (msg[i]=='u' && msg[i-1]=='u')){
            temp=second;
            second = (second+first) % mod;
            first = temp;
        } else {
            first=second;
        }
    }
    cout << second << endl;
}