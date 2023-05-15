#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#define ll long long
#define INF LONG_LONG_MAX
using namespace std;

struct strada{
    int dest;
    int peso;
    int red;
};

long long fuggi(int N, int M, vector <int> A, vector <int> B, vector <int> T, vector <int> R){
vector<vector<strada>>adj(N);
    for(int i=0;i<M;i++)
        adj[B[i]].push_back({A[i],T[i],R[i]});
    
vector<ll>distb(N,INF);
vector<ll>distr(N,INF);
vector<ll>dist(N,INF);
priority_queue<pair<ll,ll>> Q;
    Q.push({0,N-1}); 
    distb[N-1]=0;
    distr[N-1]=0;
    dist[N-1]=0;
    while(!Q.empty()) {
        ll dis=-Q.top().first;
        ll node=Q.top().second;
        Q.pop();
        for(auto [a,b,c]:adj[node]) { //a=dest, b=peso, c=rosso o blu
            if(c)
                distr[a]=min(distr[a],dist[node]+b); //aggiorno il totale per raggiungere a se seguo la strada rossa
            else
                distb[a]=min(distb[a],dist[node]+b); //aggiorno il totale per raggiungere a se seguo la strada blu
            if(distb[a]==INF)
                continue;
            ll temp;
            if(distb[a]>distr[a]) //se attiva il semaforo per far trascorrere più tempo, paga 1 (Francesco prenderebbe la strada più corta)
                temp=distb[a]-1;
            else    
                temp=distb[a]; //se la strada blu è comunque più veloce, non c'è modo per il poliziotto di fargli cambiare strada
            
            if(temp<dist[a]){ //se il mio risultato attuale è minore di quello trovato in precedenza lo aggiorno (scelta migliore per Francesco)
                Q.push({-temp,a});
                dist[a]=temp;
            }
        }
    }
    return dist[0];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // Uncomment the following lines if you want to read or write from files
  // ifstream cin("input.txt");
  // ofstream cout("output.txt");

  int N, M;
  cin >> N >> M;

  vector <int> A(M), B(M), T(M);
  vector <int> R(M, 0);
  for (int i = 0; i < M; i++) {
    cin >> A[i] >> B[i] >> T[i] >> R[i];
  }

  cout << fuggi(N, M, A, B, T, R);

  return 0;
}
