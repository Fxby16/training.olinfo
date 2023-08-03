#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF LONG_LONG_MAX

ll vert,edges,start,endd;
ll dijkstra(vector<vector<pair<ll,ll>>>);

int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
    cin>>vert>>edges>>start>>endd;
vector<vector<pair<ll,ll>>>adj(vert+1); //every vertex is 1 based (indexed from 1, not 0)
    for(int i=0;i<edges;i++)
    {
        int a,b,weight;
        cin>>a>>b>>weight;
        adj[a].push_back({b,weight});
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
