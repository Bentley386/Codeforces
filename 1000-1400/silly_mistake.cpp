#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>
#include<unordered_set>

using namespace std;

// https://codeforces.com/contest/1253/problem/B

typedef long long  ll;

int main(){
    //ifstream input;
    //input.open("test.txt",ios::in);
    int n;
    cin >> n;
    unordered_set<int> inOffice, Already;
    vector<int> list(n);
    vector<int> days;
    int day=0;

    for(int i=0;i<n;i++) cin >> list[i];

    for(int i=0;i<n;i++){
        day++;
        if (list[i] > 0){
            if (Already.count(list[i]) > 0) {
                cout << -1 << endl;
                return 0;
            }
            Already.insert(list[i]);
            inOffice.insert(list[i]);
        } else {
            if (inOffice.count(-list[i]) == 0){
                cout << -1 << endl;
                return 0;
            }
            inOffice.erase(-list[i]);
            if (inOffice.size() == 0){
                Already = unordered_set<int>();
                days.push_back(day);
                day = 0;
            }
        }
    }
    if (inOffice.size()>0) {
        cout << -1 << endl;
        return 0;
    }
    cout << days.size() << endl;
    for (int i=0;i<days.size();i++) cout << days[i] << " ";
    cout << endl;
    return 0;
}