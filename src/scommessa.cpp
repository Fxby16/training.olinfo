#include <bits/stdc++.h>
using namespace std;

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
int N,ans=0,pari,dispari,flag,k=0;
    cin>>N;
vector<int> v(N);
vector<int> anss(N);
    for(int i=0; i<N; i++){
        cin>>v[i];
    }
    for(int i=0;i<N;i++){
        pari=0,dispari=0,flag=0;
        for(int j=0;j<N;j++)
        {
            if(j==i){
                if(pari==dispari)
                    flag=1;
                pari=0,dispari=0;
                continue;
            }
            if(v[j]%2==0)
                pari++;
            else
                dispari++;
        }
        if(pari==dispari && flag==1){
            ans++;
            anss[k]=v[i];
            k++;
        }
        
    }
    cout<<ans<<endl;
    for(int i=0;i<k;i++)
        cout<<anss[i]<<" ";
    return 0;
}