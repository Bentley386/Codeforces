#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>
#include<cmath>
#include<unordered_set>

using namespace std;

// https://codeforces.com/contest/1249/problem/E

typedef long long ll;

int main(){
    int n,c;
    cin >> n >> c;
    vector<int> a(n-1),b(n-1);
    for (int i=0;i<n-1;i++) cin >> a[i];
    for (int i=0;i<n-1;i++) cin >> b[i];
    vector<int> solution(n),solutionstairs(n),solutionelevator(n);
    solution[0]=0;solutionstairs[0]=0;solutionelevator[0]=c;
    for (int i=1;i<n;i++){
        solutionstairs[i]=min(solutionstairs[i-1],solutionelevator[i-1]) + a[i-1];
        solutionelevator[i] = min(solutionstairs[i-1]+c+b[i-1],solutionelevator[i-1]+b[i-1]);
        solution[i] = min(solutionstairs[i],solutionelevator[i]);
    }
    for (int i=0;i<n-1;i++) cout << solution[i] << " ";
    cout << solution[n-1];
    return 0;
}