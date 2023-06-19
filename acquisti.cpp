#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long

vector<long long> calcola(int T, int M, vector<long long> S, vector<long long> P){
vector<ll>ans(M);
vector<pair<ll,int>>pos(M);
    for(int i=0;i<T;i++)
        pos[i]={P[i],i}; //{capienza valigia,indice originale}, mi servirà dopo aver ordinato il vettore
    sort(pos.begin(),pos.end());

ll weight=0; //peso degli oggetti scelti
ll nogg=S[0]; //numero oggetti scelti(prenderò sicuramente tutti gli oggetti di S[0] dato che hanno peso 0)
bool flag=true;
    int j=1; //parto da 1, ho già preso tutti gli oggetti in S[0]
    for(int i=0;i<M;i++){ //itero sulle valigie
        ll temp=pos[i].first; //prendo la capienza
        temp-=weight; //riduco la capienza del peso che avevo già trovato si potesse inserire in valigie con capienza minore
        while(flag){
            ll n=temp/j; //trovo quanti oggetti di peso i possono essere inseriti nella valigia
            if(n==0){ //se non ne posso mettere nessuno passo alla prossima valigia (in questa non ci sta più niente)
                break;
            }
            if(n<S[j]){ //se non posso prendere tutti gli oggetti di peso j, prendo solo quelli che ci stanno
                nogg+=n;
                weight+=(n*j);
                temp-=(n*j);
                S[j]-=n; //rimuovo gli oggetti già presi in modo da non riaggiungerli di nuovo
            }
            else{        //altrimenti aggiungo tutti gli elementi di peso j
                nogg+=S[j];
                weight+=(S[j]*j);
                temp-=(S[j]*j);
                S[j]=0;
            }
            if(j==T-1) //se sono arrivato all'ultimo peso
                if(S[j]==0) //se ho già messo tutti gli elementi non mi serve più vedere se ne posso aggiungere altri
                    flag=false;
                else        //altrimenti passo alla prossima valigia
                    break;
            else if(S[j]==0) //se ho finito gli elementi di peso j, passo al peso successivo
                ++j;
        }
        ans[pos[i].second]=nogg; //inserisco il numero di oggetti che posso inserire in questa valigia
    }
    return ans;
}

//grader
int main() {
    ios::sync_with_stdio(false);
    
    int T, M;
    cin >> T >> M;

    vector<long long> S(T), P(M);

    for (long long& x : S) cin >> x;
    for (long long& x : P) cin >> x;

    auto R = calcola(T, M, S, P);

    for (long long x : R) cout << x << ' ';
    cout << endl;

    return 0;
}
