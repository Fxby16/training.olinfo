#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


int main()
{
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
int N,i,max;
int ans=0;
    cin>>N>>max;
    vector<int>snack(N);
    for(i=0;i<N;i++)
        cin>>snack[i];
    sort(snack.begin(),snack.end());
    i=0;
    while(i<N)
    {
        if((snack[i]+snack[i+1])<=max && i<N-1)
        {
            ans++;
            i+=2;
        }
        else
        {
            ans+=N-i;
            break;
        }
    }
    cout<<ans;

    return 0;
}