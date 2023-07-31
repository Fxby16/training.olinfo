#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
#define MAXN 200000

struct children{
int sum; //somma delle risposte dei figli
multiset<int,greater<int>>M; //risposte per i figli, ordinate in ordine crescente

    void insert(int n){ //aggiungo un figlio
        sum+=n;
        M.insert(n);
    }

    void erase(int n){ //elimino un figlio
        sum-=n;
        M.erase(M.find(n));
    }

    int get_ans(){ //risposta per il nodo corrente
        return 1+sum-(*M.begin()); //mi stacco dal nodo con più figli
    }
};

children dp[MAXN];
vector<vector<int>>adj(MAXN);
int ans[MAXN];

void update_children(int node,int par){ //aggiorno i valori per far diventare node la radice dell'albero
    dp[par].erase(dp[node].get_ans()); //rimuovo node da par, node non è più figlio di par
    dp[node].insert(dp[par].get_ans()); //aggiungo par a node, par diventa il figlio
}

void dfs(int node,int par){ //dfs iniziale, calcolo la risposta per il nodo 0
    for(auto i:adj[node]){
        if(i==par)
            continue;
        dfs(i,node); //dfs sul figlio
        dp[node].insert(dp[i].get_ans());
    }
}

void change_root(int node,int par){
    ans[node]=dp[node].get_ans(); //salvo la risposta per il nodo corrente

    for(auto i:adj[node]){ //sposto la radice sui figli
        if(i==par)
            continue;
        update_children(i,node); //aggiorno i valori per far diventare i la radice
        change_root(i,node); //cambio la radice
        update_children(node,i); //resetto il nodo corrente in modo che diventi di nuovo la radice (per poter spostare la radice sugli altri figli)
    }
}

int main(){
ios::sync_with_stdio(false);
cin.tie(0);

int N;
    cin>>N;

    for(int i=0;i<N-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0,-1);
    change_root(0,-1);

    for(int i=0;i<N;i++)
        cout<<ans[i]<<' ';

    return 0;
}