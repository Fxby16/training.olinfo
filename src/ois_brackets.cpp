#include <iostream>
#define pb push_back
#define MAXN 400000
using namespace std;

int S[MAXN];

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int n,k,T;
    cin>>T;
    for(int t=0;t<T;t++){
        cin>>n>>k;
        int sp=0;
        for(int i=0;i<n;i++){
            cin>>k;
            if(sp>0 && S[sp-1]==k)
                sp--;
            else
                S[sp++]=k;
        }
        if(sp==0)
            cout<<1<<'\n';
        else 
            cout<<0<<'\n';
    }
    return 0;
}