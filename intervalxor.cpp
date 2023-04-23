#include <bits/stdc++.h>
using namespace std;

int maxxor(int n){ //il massimo xor nel range 0-n è dato da tutti i bit rappresentanti una potenza di 2 minore o uguale a n posti a 1
int ans=0;
    for(int i=1;i<=n;i<<=1)
        ans|=i;

    return ans;
}

int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

int N,n;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>n;
        if(n%4==0)
            cout<<n<<' '<<maxxor(n)<<endl;
        else if(n%4==1)
            cout<<1<<' '<<n<<endl;
        else if(n%4==2)
            cout<<n+1<<' '<<maxxor(n+1)<<endl;
        else
            cout<<0<<' '<<n<<endl;
    }

    return 0;
}