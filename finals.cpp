#include <bits/stdc++.h>
using namespace std;

int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
    int ans=0,temp=0;
    int n1,n2,n3,N,P;
    cin>>N>>P;
    cin>>n1>>n2>>n3;
    temp=n1+n2+n3;
    for(int i=0;i<N-1;i++)
    {
        int k1,k2,k3;
        cin>>k1>>k2>>k3;
        ans=max(ans,(k1+k2+k3+(100*P))-temp+1);
    }
    cout<<ans;

    return 0;
}