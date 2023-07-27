#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
#define ll long long

long long revenue(int N, int K, vector<long long> A){
vector<ll>neg;
vector<ll>pos;
map<ll,bool>checked;

    sort(begin(A),end(A),[](ll a,ll b){ return abs(a)<abs(b);}); //ordino il vettore in ordine crescente in base ai valori assoluti 
    
    for(int i=0;i<N;i++){ //metto in pos i valori positivi e in neg quelli negativi
        if(A[i]>0)
            pos.push_back(A[i]);
        else if(A[i]<0)
            neg.push_back(-A[i]);
    }

    ll sum=0;
    ll ans=LONG_LONG_MIN;

    for(int i=0;i<N;i++){

        ll x=abs(A[i]); //inizializzo la tolleranza come il valore assoluto di A[i]
        if(checked[x]){ //se ho già controllato questa tolleranza aggiungo il valore alla somma e continuo
            sum+=A[i];
            continue;
        }
        else
            checked[x]=true; //altrimenti mi segno che ho già controllato questa tolleranza

        ll cost=K*x; //inizializzo il costo
        
        ll pos_sum=0;
        if(!pos.empty()){
            int pos_=lower_bound(begin(pos),end(pos),x)-begin(pos);
            pos_sum=(pos.size()-pos_)*x; //sommo tutti i valori >=x
            if(pos_sum==x && pos.back()<x){ //se tutti i valori sono <x la somma va a 0
                pos_sum=0;
            }
        }
        
        ll neg_sum=0;
        if(!neg.empty()){
            int pos_=lower_bound(begin(neg),end(neg),x)-begin(neg);
            neg_sum=(neg.size()-pos_)*x; //sommo tutti i valori <=x
            if(neg_sum==x && neg.back()<x){ //se tutti i valori sono <x la somma va a 0
                neg_sum=0;
            }
        }

        ans=max(ans,pos_sum-neg_sum+sum-cost); //vedo se ho trovato un guadagno migliore

        sum+=A[i]; //aggiungo l'elemento corrente alla somma
    }
    return max(ans,0LL); //la tolleranza ideale è un valore presente in A[i] o 0. se la tolleranza è 0 il guadagno è 0
}