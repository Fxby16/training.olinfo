#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,K;
    cin>>N>>K;

    vector<int>v(N);
    vector<int>colors(K,0);
    for(int i=0;i<N;i++){
        cin>>v[i];
        colors[v[i]]++;
    }

    int left=0,right=N-1;
    
    while(true){
        bool changed=false;
    
        if(colors[v[right]]-1>0){
            colors[v[right]]--;
            right--;
            changed=true;
        }
        if(colors[v[left]]-1>0){
            colors[v[left]]--;
            left++;
            changed=true;
        }
        
        if(!changed)
            break;
    }
    
    cout<<right-left+1<<endl;
    
    return 0;
}