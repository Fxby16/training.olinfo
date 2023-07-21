#include <iostream>
#include <vector>
#include <algorithm>
#pragma GCC optimize ("Ofast")
using namespace std;

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int N;
    cin>>N;
vector<int>v(N+1);
vector<bool>visited(N+1,false);
    for(int i=1;i<=N;i++)
        cin>>v[i];

int div=0,ans=N;
    for(int i=1;i<=N;i++){
        if(visited[i]) //se ho già visitato questo elemento continuo. è già incluso in un ciclo
            continue;
        --ans; //rimuovo dal numero di elementi il numero di cicli del grafo. un ciclo può essere formato anche da un elemento
        for(int n=i;!visited[n];n=v[n]){ //itero su tutti gli elementi del ciclo che parte da i. il ciclo è formato da più di un elemento se il numero non si trova nella posizione corretta
            div=__gcd(div,abs(n-v[n])); //trovo il massimo comune divisore tra tutti gli elementi che sono da scambiare
            visited[n]=true; //marchio come visitato questo elemento
        }
    }

    for(int i=1;i<=N;i++){
        if(div%i) //se i è un divisore di div, allora con la bacchetta i ottieniamo lo stesso identico risultato, se non lo è, l'array non è ordinabile
            cout<<-1<<' ';
        else
            cout<<ans<<' ';
    }

    return 0;
}