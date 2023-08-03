#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;

#define MAX_N 50000
#define MAX_M 10000000
#define INF INT_MAX

static int N, M;
static int R[MAX_M][2];
static int L[MAX_M];
static int K;
static int P[MAX_N];
static int solution;

struct strada{
    int dest;
    int peso;
};

extern int travel_plan(int N, int M, int R[][2], int L[], int K, int P[]){
vector<vector<strada>>adj(N);
    for(int i=0;i<M;i++){
        adj[R[i][0]].push_back({R[i][1],L[i]}); //bidirezionale
        adj[R[i][1]].push_back({R[i][0],L[i]});
    }
priority_queue<pair<int,int>>Q;
vector<pair<int,int>>dist(N,{INF,INF}); //abbiamo al massimo due possibilità, il caso migliore, e il caso leggermente peggiore
vector<bool>visited(N,false);
    for(int i=0;i<K;i++){
        Q.push({0,P[i]}); //parto dalle uscite. la risposta finale sarà nel nodo 0
        dist[P[i]]={0,0};
    }
    while (!Q.empty()) {
        int dis=-Q.top().first;
        int node= Q.top().second;
        Q.pop();
        if(visited[node]) //se l'ho già visto non mi serve andare avanti con questo
            continue;
        visited[node]=true;
        for (auto [a,b]:adj[node]){
            int temp=b+dis; //distanza da node ad a
            if(temp<dist[a].first){ //se questo è il percorso più corto, il percorso leggermente peggiore diventa quello che prima era il migliore
                dist[a].second=dist[a].first;
                dist[a].first=temp;
                Q.push({-dist[a].second,a});
            }
            else if(temp<dist[a].second){ //se il percorso attuale non è il migliore ma è comunque meglio di quello leggermente peggiore lo aggiorno
                dist[a].second=temp;
                Q.push({-dist[a].second,a});
            }
        }
    }
    return dist[0].second; //la risposta non è la distanza migliore ma quella leggermente peggiore come richiesto dal testo
}

int main()
{
  int i;
  cin>>N>>M>>K;
  for(i=0; i<M; i++)
    cin>>R[i][0]>>R[i][1]>>L[i];
  for(i=0; i<K; i++)
    cin>>P[i];
  printf("%d\n", travel_plan(N,M,R,L,K,P));
  return 0;
}
