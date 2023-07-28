#include <iostream>
#include <vector>
#include <variant>
#include <queue>
#define LEFT 0
#define MID 1
#define RIGHT 2

using namespace std;

variant<bool, vector<int>> find_tour(int N, vector<int> A){
    if(A[0]!=2 && A[N-1]!=2) //in un tour valido si passa per A[0] e per A[N-1] 2 volte
        return false;

vector<int>type(N);
int opened=0;

    for(int i=0;i<N;i++){ //dato che ogni negozio è l'estremo di due intervalli, i negozi si possono dividere in tre categorie
        if(A[i]-opened==0){ //il negozio corrente è l'estremo destro di due intervalli
            type[i]=RIGHT;
            opened-=2;
        }
        else if(A[i]-opened==1) //il negozio corrente è l'estremo destro di un intervallo e l'estremo sinistro di un altro
            type[i]=MID;
        else if(A[i]-opened==2){ //il negozio corrente è l'estremo sinistro di due intervalli
            type[i]=LEFT;
            opened+=2;
        }else //se il negozio non appartiene a nessuna di queste categorie, non esiste un tour valido
            return false;

        if(opened<0) //non posso aprire un numero di intervalli negativo
            return false;
    }
    if(opened!=0) //tutti gli intervalli devono chiudersi
        return false;

vector<int>tour;
    tour.push_back(0); //il tour inizia sempre dal negozio 0

queue<int>Q;
    for(int i=1;i<N-1;i++){
        if(type[i]==LEFT) //aggiungo il negozio in coda, verrà inserito quando verrà raggiunto un negozio di tipo RIGHT
            Q.push(i);
        else if(type[i]==MID) //aggiungo il negozio direttamente al tour
            tour.push_back(i);
        else{
            if(Q.empty())
                return false;
            tour.push_back(i); //come si può vedere dal primo esempio, per ottenere un tour corretto bisogna scambiare il negozio di categoria LEFT trovato con quello successivo di categoria RIGHT
            tour.push_back(Q.front());
            Q.pop();
        }
    }
    tour.push_back(N-1); //il tour finisce sempre al negozio N-1
    return tour;
}
