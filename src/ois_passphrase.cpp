#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,K;
    cin>>N>>K;

    string s;
    cin>>s;

    int k=0;
    for(int i=0;i<s.size()-1;){
        if(k<K && s[i]<s[i+1]){
            k++;
            s.erase(i,1);
            if(i>0){
                i--;
            }
        }else{
            i++;
        }
    }

    if(k<K){
        s.erase(0,K-k);
    }

    cout<<s<<endl;

    return 0;
}