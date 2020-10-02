#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>
#include<cmath>
#include<unordered_set>

#define INF 1000000000

using namespace std;
typedef long long  ll;

bool isBeautiful(const vector<int>&,int);

int main(){
    int n,k;
    char temp;
    cin >> n >> k;
    vector<int> digits(n);
    for (int i=0;i<n;i++) {
        cin >> temp;
        digits[i] = int(temp)-int('0');
    }
    if (isBeautiful(digits,k)) {
        cout << n << endl;
        for (int x : digits) cout << x;
        return 0;
    }
    vector<int> old = digits;
    for (int i=k-1;i>=0;i--){
        int j=i;
        while (j+k<n) {
            digits[j+k]=digits[j];
            j+=k;
        }
    }
    bool bigger=true;
    for (int i=0;i<n;i++){
        if (old[i] > digits[i]) {
            bigger=false;
            break;
        }
        if (digits[i] > old[i]) break;
    }
    if (!bigger) {
        for (int i=k-1;i>=0;i--){
            digits[i] = (digits[i] + 1) % 10;
            int j=i;
            while (j+k<n){
                digits[j+k] = digits[j];
                j+=k;
            }
            if (digits[i]!=0) break;
        }
    }
    if (digits[0]==0){
        n++;
        digits = vector<int>(n);
        for (int i=0;i<n;i+=k) digits[i] = 1;
    }
    cout << n << endl;
    for (int x : digits) cout << x;
    return 0;
}

bool isBeautiful(const vector<int>& x, int k){
    int m = x.size();
    for (int i=0;i<k;i++){
        int j = i;
        while (j+k<m){
            if (x[j] != x[j+k]) return false;
            j+=k;
        }
    }
    return true;
}