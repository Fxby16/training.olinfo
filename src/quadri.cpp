#include <bits/stdc++.h>
using namespace std;

int quadri(int N, long long M, int V[]){
long long somma=0;
int start=0,endd=0;
int ans=INT_MAX;
    for(;endd<N;endd++){
        if(V[endd]>M) //se il valore della cella corrente supera la somma significa che non possiamo avere nemmeno una sequenza di 1 elemento
            return 0;
        somma+=V[endd];
        while(somma>M){ //se la somma è minore del massimo consentito diminuisco il range
            somma-=V[start];
            start++;
            ans=min(ans,endd-start+1); //aggiorno la risposta dato che ho fatto un aggiornamento
        }
    }
    if(ans==INT_MAX) //se ans è ancora uguale a INT_MAX significa che la somma di tutti i valori nell'array è <=M, quindi la risposta è il numero di valori nell'array
        return N;
    else
        return ans;
}

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("abc_quadri.input5.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
int N;
long long M;
int V[200000];
    cin>>N>>M;
    for(int i=0;i<N;i++)
        cin>>V[i];
    cout<<quadri(N,M,V);

    return 0;
}