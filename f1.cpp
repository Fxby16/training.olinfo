#include <bits/stdc++.h>
using namespace std;
int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
int N,temp,minnum=INT_MAX,hamiltonrace=0,verstappenrace=0;
cin>>N;
string name;
    for(int i=0;i<2;i++)
        for(int j=0;j<N;j++)
        {
            cin>>temp;
            if(temp<minnum)
            {
                if(i==0)
                    name="Hamilton";
                else    
                    name="Verstappen";
                minnum=temp;
            }
            if(i==0)
                hamiltonrace+=temp;
            else
                verstappenrace+=temp;
        }
    if(hamiltonrace<verstappenrace)
        cout<<"Hamilton\n";
    else
        cout<<"Verstappen\n";
    cout<<name;
    return 0;
}