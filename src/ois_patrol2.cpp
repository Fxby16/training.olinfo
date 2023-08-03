#include <bits/stdc++.h>
using namespace std;

int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
int vert,edges,police;
    cin>>vert>>edges>>police;
vector<vector<int>>adj(vert);
vector<int>v(police);
    for(int i=0;i<edges;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<police;i++)
        cin>>v[i];
    
    vector<int>dist(vert,INT_MAX);
    priority_queue<pair<int,int>> Q;
    Q.push({0,0});
    dist[0]=0;
    while(!Q.empty())
    {
        int node=Q.top().second;
        int dis=-Q.top().first;
        Q.pop();
        if(dis>dist[node])
            continue;
        for(auto a:adj[node])
        {
            int temp=1+dis+(v[(dis+1)%police]==a); //dis equivale ai tunnel attraversati. ((dis+1)%police) rappresenta dove si troverà la guardia nel prossimo minuto.
            if(dist[a]>temp)                       //se la guardia si trova al nodo 'a' dobbiamo sommare 1 (il tempo da aspettare) alla distanza attuale (dis) + 1 (il tempo per raggiungere il prossimo tunnel)
            {
                dist[a]=temp;
                Q.push({-dist[a],a});
            }
        }
    }
    cout<<dist[vert-1];

    return 0;
}