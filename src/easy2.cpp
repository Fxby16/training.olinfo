#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
ios::sync_with_stdio(false);
cin.tie(0);
int maxx=INT_MIN,N,temp;
    cin>>N;
vector<int>A(N);
vector<int>B(N);
    for(int i=0;i<N;i++)
    {
        cin>>A[i]>>B[i];
        temp=A[i]+B[i];
        if(temp%2==0)
            maxx=max(maxx,temp);
    }
    if(maxx!=INT_MIN)
        cout<<maxx;
    else
        cout<<-1;

    return 0;
}