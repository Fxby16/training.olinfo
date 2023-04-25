#include <bits/stdc++.h>
using namespace std;
#define MAXN 1e5

int N,ans=0;
vector<int>visited(MAXN,false);
vector<int>v(MAXN);
vector<int>v2(MAXN);

void dfs(int i,int n)
{
    if(visited[i])
    {                          //v2[i] rappresenta quante case avevo passato prima di arrivare alla casa i
        ans=max(n-v2[i],ans);  //essendo che il loop inizia e finisce nella casa i, devo sottrarre le case che
    }                          //avevo visitato in precedenza
    else                      
    {
        visited[i]=true;
        v2[i]=n;        //mi salvo quante case ho visitato fino ad ora dall'inizio della dfs
        dfs(v[i],n+1);  //vado alla casa successiva
    }
}

int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
    cin>>N;

    for(int i=0;i<N;i++)
        cin>>v[i];

    for(int i=0;i<N;i++)
        if(!visited[i])
            dfs(i,0);

    cout<<ans;

    return 0;
}