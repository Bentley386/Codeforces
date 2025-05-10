#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;

// https://codeforces.com/contest/1617/problem/D2

typedef long long  ll;

bool ask(int i1, int i2, int i3){ //returns true if there are more crewmates than impostors
    i1++;i2++;i3++;
    cout << "? " << i1 << " " << i2 << " " << i3 << endl;
    int r;
    cin >> r;
    return r; 
}

void solve(){
    int n; cin >> n;
    vector<bool> triples(n/3); //result of ask for each triple
    int index0,index1; //indices of triplets for which triples[i] = true/false
    for (int i=0;i<n/3;++i){
        triples[i] = ask(3*i,3*i+1,3*i+2);
        if (triples[i]) index1=i;
        else index0 = i;
    }

    int crewmate,impostor; //actual indices of a crewmate/impostor
    if (ask(3*index1,3*index0+1,3*index0+2)){
        crewmate = 3*index1;
        impostor = 3*index0;
    } else if (ask(3*index1+1,3*index0+1,3*index0+2)){
        crewmate = 3*index1+1;
        impostor = 3*index0;
    } else if (ask(3*index1+2,3*index0+1,3*index0+2)){
        crewmate = 3*index1+2;
        impostor = 3*index0;
    } else {
        impostor = 3*index0+1;
        if (!ask(impostor,3*index1+1,3*index1+2)) {
            crewmate = 3*index1;
        } else if (!ask(3*index1,impostor,3*index1+2)){
            crewmate = 3*index1+1;
        } else if (!ask(3*index1,3*index1+1,impostor)){
            crewmate = 3*index1+2;
        } else {
            crewmate = 3*index1;
        }
    }

    vector<int> impostors;
    impostors.push_back(impostor);
    for (int i=0;i<3;++i){
        int ind = 3*index0+i;
        if (ind == impostor) continue;
        if (!ask(crewmate,impostor,ind)) impostors.push_back(ind);
    }
    for (int i=0;i<3;++i){
        int ind = 3*index1+i;
        if (ind == crewmate) continue;
        if (!ask(crewmate,impostor,ind)) impostors.push_back(ind);
    }
    
    for (int i=0;i<n/3;++i){
        if (i==index1 || i==index0) continue;
        if (triples[i]){ //majority crewmates
            if (ask(3*i,3*i+1,impostor)){
                if (!ask(impostor,crewmate,3*i+2)) impostors.push_back(3*i+2);
            } else {
                if (ask(impostor,crewmate,3*i)) impostors.push_back(3*i+1);
                else impostors.push_back(3*i);
            }
        } else { //majority imposters
            if (!ask(3*i,3*i+1,crewmate)){
                impostors.push_back(3*i);
                impostors.push_back(3*i+1);
                if (!ask(3*i+2,impostor,crewmate)) impostors.push_back(3*i+2);
            } else {
                impostors.push_back(3*i+2);
                if (ask(3*i,impostor,crewmate)) impostors.push_back(3*i+1);
                else impostors.push_back(3*i);
            }
        }
    }

    cout << "! " << impostors.size() << " ";
    for (int x : impostors) cout << x+1 << " ";
    cout << endl;
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}