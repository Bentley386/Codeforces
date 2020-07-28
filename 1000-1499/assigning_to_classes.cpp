#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int t,n,current;
    cin >> t;
    vector<int> students;

    for (int i=0;i<t;i++){
        cin >> n;
        for (int j=0;j<2*n;j++){
            cin >> current;
            students.push_back(current);
        }
        sort(students.begin(),students.end());
        cout << abs(students[n]-students[n-1]) << "\n";
        students.clear();
    }

    return 0;
}