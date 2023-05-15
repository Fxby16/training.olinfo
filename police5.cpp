#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
#define INF INT_MAX

struct strada{
    int dest;
    int peso;
    int explode;
};

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
int N,M,T;
    cin>>N>>M>>T;
vector<vector<strada>>adj(N);
    for(int i=0;i<M;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        adj[a].push_back({b,c,d});
    }

    vector<int>dist(N,INF);
    priority_queue<pair<int,int>> Q;
    Q.push({0, 0}); 
    dist[0] = 0;
    while (!Q.empty()) {
        int dis=-Q.top().first;
        int node=Q.top().second;
        Q.pop();
        if (dis>dist[node])
            continue;
        for (auto [a,b,c]:adj[node]) {
            if (dist[a]>b+dis && !(((T>dis && T<b+dis)|| T<=dis) && c)) {
                dist[a]=b+dis;
                Q.push({-dist[a], a});
            }
        }
    }
    if(dist[N-1]!=INT_MAX)
        cout << dist[N-1] << "\n";
    else 
        cout<<-1<<'\n';

    return 0;
}