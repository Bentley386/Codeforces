#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>

using namespace std;
typedef long long int li;

int main(){
    //ifstream input;
    //input.open("test.txt",ios::in);
    string s;
    getline(cin,s);
    int n = s.length();
    int lasta = -1;
    int numas = 0;
    int x;
    for (int i=0; i<n; i++){
        if(s[i]=='a') {
            lasta=i; //6
            numas++; //4
        }
    }
    if (numas+n % 2 == 1) {
        cout << ":(\n";
        return 0;
    }
    x = (numas+n)/2-lasta-1;
    string prvi="";
    for (char i:  s.substr(0,lasta+x+1)){
        if (i!='a') prvi += i;
    }
    string drugi = s.substr(lasta+x+1,n);
    if (prvi==drugi) cout << s.substr(0,lasta+x+1) << endl;
    else cout << ":(\n";

    // breza = lasta+1 -numas = dolzina stringa brez a-jev 
    //iscemo x da breza+x = n-(lasta+1)-x  ->   2x = n - lasta-1-breza  = n -2lasta-2+numas
    //x=(numas+n)/2 -lasta-1  

    //input.close();  
    return 0;
}