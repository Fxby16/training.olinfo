#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
#define pii pair<int,int>
#define ll long long
#define MAXN 1e5

vector<ll>dist(MAXN+1);
vector<vector<pii>>adj(MAXN+1);

void dfs(int node,ll d,int par){
    dist[node]=d;
    for(auto [i,w]:adj[node]){
        if(i==par)
            continue;

        dfs(i,d+w,node);
    }
}

int main(){
ios::sync_with_stdio(false);
cin.tie(0);

int N,K;
    cin>>N>>K;
ll l=0;

    for(int i=0;i<N-1;i++){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
        l+=w;
    }

    if(K==1){ //bisogna ritornare nella città di partenza, si percorre la stessa strada 2 volte, quindi la risposta è il doppio della lunghezza totale delle strade
        cout<<l*2;
        return 0;
    }
    
    dfs(1,0,-1); //dfs dalla prima città
    dfs(max_element(begin(dist),end(dist))-begin(dist),0,-1); //dfs dalla città più lontana dalla prima città

    cout<<(2*l)-*max_element(begin(dist),end(dist)); //la risposta è la lunghezza totale delle strade * 2 - la distanza maggiore tra due città
                                                     //conviene che gli estremi del percorso siano le due città più lontane, in modo da percorrere
                                                     //la strada più lunga una sola volta, risparmiando il massimo possibile
    return 0;
}