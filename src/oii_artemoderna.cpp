#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;

bool ordina(int N, vector<int> V, vector<int> &L){
int start=0,end_=0;
int lastblocknum=INT_MIN;
    for(int i=0;i<N;i++){
        if(V[i]<lastblocknum)
            return false;
        if(i>0 && V[i]>V[i-1]){
            L.push_back(end_-start);
            lastblocknum=V[start];
            start=end_=i;
        }
        end_++;
    }
    L.push_back(end_-start);
    return true;
}