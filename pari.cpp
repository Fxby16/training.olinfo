#include <iostream>
using namespace std;

int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
int N;
    cin>>N;
    if(N%2==0)
        cout<<"pari";
    else
        cout<<"dispari";

    return 0;
}