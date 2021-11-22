#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    string sequence;
    vector<int> slots(7);
    cin >> n;
    while (n--){
        cin >> sequence;
        for (int i=0;i<7;i++) slots[i] += (int) sequence[i] - 48;
    }
    int max=0;
    for (int x : slots) {
        if (x>max) max=x;
    }
    cout << max << endl;
    return 0;
}