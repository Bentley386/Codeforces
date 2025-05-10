#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>

using namespace std;

// https://codeforces.com/contest/1276/problem/A

typedef long long  ll;

int main(){
    //ifstream input;
    //input.open("test.txt",ios::in);
    int t,n,i;
    cin >> t;
    string orig;
    vector<int> pos;
    getline(cin,orig);
    while (t--){
        pos = vector<int>();
        getline(cin,orig);
        n = orig.size();
        i=0;
        while (i<n){
            if (orig[i]=='t'){
                if (n-i >= 5){
                    if (orig.substr(i,5) == "twone"){
                        pos.push_back(i+3);
                        i+=5;
                        continue;
                    }
                } if (n-i >= 3){
                    if (orig.substr(i,3) == "two"){
                        pos.push_back(i+2);
                        i+=3;
                        continue;
                    }
                }
            } else if (orig[i]=='o'){
                if (n-i >= 3){
                    if (orig.substr(i,3) == "one"){
                        pos.push_back(i+2);
                        i+=3;
                        continue;
                    }
                }
            }
            i++;
        }
        cout << pos.size() << "\n";
        if (pos.size() > 1){
            for(int i=0;i<pos.size()-1;i++) cout << pos[i] << " ";
        } 
        if (pos.size() > 0) {
            cout << pos[pos.size()-1] << "\n";
        }
    }
    return 0;
}