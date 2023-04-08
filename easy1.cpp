#include <iostream>
#include <climits>
using namespace std;

int main()
{
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
ios::sync_with_stdio(false);
cin.tie(0);
int maxx=INT_MIN,temp,N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>temp;
        maxx=max(maxx,temp);
    }
    cout<<maxx;

    return 0;
}