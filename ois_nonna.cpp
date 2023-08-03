#include <bits/stdc++.h>
using namespace std;

vector<int>P;
int N,K;

int mangia(int i,int k,vector<vector<int>>&memo){
    if(k>=K) //se sono arrivato a un valore che sia almeno K ritono k
        return k;
    if(i>=N) //se ho finito gli elementi da provare ritorno un valore neutro
        return INT_MAX;
    if(memo[k][i]!=-1) //se ho già incontrato questo caso, ritorno il valore che avevo già calcolato
        return memo[k][i];
        
    int mangio=mangia(i+1,k+P[i],memo); //calcolo il valore se mangio la portata
    if(mangio==K) //se posso ottenere esattamente K, ritorno
        return K;
    int nonmangio=mangia(i+1,k,memo); //calcolo il valore se non mangio la portata
    int temp=min(mangio,nonmangio); //il risultato è il più piccolo valore >=K
    memo[k][i]=temp; //salvo il valore appena trovato in caso mi serva di nuovo
    return temp;
}

int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
    cin>>N>>K;
    P.resize(N);
    for(int i=0;i<N;i++)
        cin>>P[i];
    vector<vector<int>>memo(K+1,vector<int>(N,-1));
    cout<<mangia(0,0,memo);

    return 0;
}
