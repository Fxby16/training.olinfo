#include <bits/stdc++.h>
using namespace std;

int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
int N,K,ans=0;
    cin>>N>>K;
vector<int>visited(N+1,false);
vector<int>v(N+1);
bool flag=true;

    for(int i=1;i<=N;i++)
        cin>>v[i];
int i=1;
    while(flag)
    {
        if(i==K){
            flag=false;
        }
        else if(visited[v[i]])
        {
            ans=-1;
            flag=false;
        }
        else
        {
            visited[i]=true;
            ans++;
            i=v[i];
        }
    }

    cout<<ans;

    return 0;
}