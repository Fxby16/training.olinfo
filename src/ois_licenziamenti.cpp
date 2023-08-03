#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000

vector<vector<int>>adj(MAXN);
vector<int>minn(MAXN,INT_MAX);

int licenzia(int N, int B[], int C[]) {
int ans=0;
    if(N==1)    //se abbiamo solo 1 dipendente sicuramente non dobbiamo licenziare nessuno
        return 0;
    
    for(int i=0;i<N;i++)
    {
        if(C[i]!=-1)        //in caso non sia il boss lo inseriamo nella lista di adiacenza
            adj[C[i]].push_back(i);
    }

    //DFS
    stack<int>S;    
    S.push(0);
    int current;
    minn[0]=B[0];
    while(!S.empty())
    {
        current=S.top();
        S.pop();
        for(auto k:adj[current])
        {
            S.push(k);
            if(B[k]>minn[current])  //se la bravura del dipendente è maggiore di quella di un suo superiore va licenziato
                ans++;
            minn[k]=min(B[k],minn[current]); //aggiorniamo la bravura massima che possono avere i dipendenti successivi
        }
    }

    return ans; //ritorniamo il risultato finale
}


int B[MAXN], C[MAXN];

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>B[i]>>C[i];

    cout<<licenzia(n,B,C);

    return 0;
}
