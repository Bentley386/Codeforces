#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>

using namespace std;

// https://codeforces.com/contest/1320/problem/A

typedef long long  ll;

int main(){
    //ifstream input;
    //input.open("test.txt",ios::in);
    int n;
    int curr;
    cin >> n;
    map<int,ll> vrednosti;
    for (int i=0;i<n;i++) {
        cin >> curr;
        if(vrednosti.count(curr-(i+1)) == 0) vrednosti[curr-(i+1)] = curr;
        else vrednosti[curr-(i+1)] += curr;
    }
    ll max=0;
    for (pair<int,ll> x : vrednosti) {
        if (x.second>max) max=x.second;
    }
    cout << max << endl;

    return 0;
}