#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,K;
    cin>>N>>K;

    vector<string>v(N);
    for(int i=0;i<N;i++){
        cin>>v[i];
    }

    int line_width=0;
    for(int i=0;i<N;i++){
        if(line_width+v[i].size()+((i==0)?0:1)<=K){
            if(line_width>0){
                cout<<" ";
            }
            line_width+=v[i].size()+((i==0)?0:1);
            cout<<v[i];
        }else{
            line_width=v[i].size();
            cout<<"\n"+v[i];
        }
    }

    cout<<'\n';

    return 0;
}