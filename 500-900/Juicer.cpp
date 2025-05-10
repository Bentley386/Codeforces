#include<iostream>

using namespace std;

// https://codeforces.com/contest/709/problem/A

int main(){
    int n,b,d;
    int current=0;
    int count=0;
    int a;
    cin >> n >> b >> d;
    for (int i=0;i<n;i++){
        cin >> a;
        if (a>b) continue;
        current += a;
        if (current > d){
            count++;
            current=0;
        }
    }
    cout << count;
    return 0;
}