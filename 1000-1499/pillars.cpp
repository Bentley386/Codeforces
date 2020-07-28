#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;
typedef long long int li;

bool check(vector<int> discs, int n);

int main(){
    //ifstream input;
    //input.open("test.txt",ios::in);
    int n;
    cin >> n;
    vector<int> discs(n);
    for(int i=0; i<n;i++) cin >> discs[i];
    if(check(discs,n)) cout << "YES\n";
    else cout << "NO\n";
    //input.close();  
    return 0;
}

bool check(vector<int> discs, int n){
    int maxind = max_element(discs.begin(),discs.end())-discs.begin(); 
    int current = discs[maxind];
    vector<int> desni(discs.begin()+maxind+1,discs.end());
    reverse(desni.begin(),desni.end());
    vector<int> levi(discs.begin(),discs.begin()+maxind);

    for (int i=0; i<n-1;i++){
        if (levi.size() == 0) {
            if (current > desni[desni.size()-1]) {
                current = desni[desni.size()-1];
                desni.pop_back();
            } else return false;
        }
        else if (desni.size() == 0){
            if (current > levi[levi.size()-1]) {
                current = levi[levi.size()-1];
                levi.pop_back();
            } else return false;
        }
        else{
            if (levi[levi.size()-1] > desni[desni.size()-1]){
                if (current > levi[levi.size()-1]){
                    current = levi[levi.size()-1];
                    levi.pop_back();
                } else return false;
            } else {
                if (current > desni[desni.size()-1]){
                    current = desni[desni.size()-1];
                    desni.pop_back();
                } else return false;
            }
        }
    }
    return true;
}