#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
ll N,K;
    cin>>N>>K;
ll n=1,k;
ll x=1;

   if(K==1)
   {
        cout<<(long long)pow(10,N)-2<<" "<<(long long)pow(10,N)-1<<endl;
        return 0;
   }

    while(((int)log10(n)+1)<N){
        n=K*x;
        x*=10;
    }
    if(((int)log10(n-K)+1)>=N)    
        n-=K;
    if(n==K)
        n+=K;
    if((int)log10(n)+1==N)
    {
        k=n+K;
        int k2=n-K;
        if((int)log10(k)+1==N)
        {
            cout<<n<<" "<<k;
        }
        else if((int)log10(k2)+1==N)
            cout<<n<<" "<<k2;
        else{
            cout<<"0 0";
        }
    }
    else
        cout<<"0 0";

    return 0;
}