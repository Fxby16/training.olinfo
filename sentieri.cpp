#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF LONG_LONG_MAX

ll vert,start,endd;
ll dijkstra(vector<vector<pair<ll,ll>>>);

int main()
{
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
ll A,B;
    cin>>vert>>A>>B;
    start=1;
    endd=vert;
    if(B==0)
    {
        cout<<0;
        return 0;
    }
vector<vector<pair<ll,ll>>>adj(vert+1); 
    for(int i=0;i<A;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back({b,0});
     adj[b].push_back({a,0});
    }
    for(int i=0;i<B;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back({b,1});
     adj[b].push_back({a,1});
    }
    cout<<dijkstra(adj);
    return 0;
}
ll dijkstra(vector<vector<pair<ll,ll>>>adj)
{
vector<ll>dist(vert+1,INF);
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> Q;
Q.push({start,0});
dist[start]=0;
    while(!Q.empty())
    {
        ll temp1=Q.top().first;
        ll temp2=Q.top().second;
        Q.pop();
        if(temp2>dist[temp1])
            continue;
        for(auto [a,b]:adj[temp1])
        {
            if(dist[a]>(b+temp2))
            {
                dist[a]=b+temp2;
                Q.push({a,dist[a]});
            }
        }
    }
    return dist[endd];
}
