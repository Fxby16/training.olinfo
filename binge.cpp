#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
#define ll long long

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int M,N;
    cin>>M>>N;
int ep;
int dur;
ll tot_days=0;
int rem_time=0;

    for(int i=0;i<N;i++){
    	cin>>ep>>dur;
        if(i>0 && dur<=rem_time){ //se nel giorno precedente mi è rimasto del tempo, vedo se posso sfruttarlo
            int temp=min(rem_time/dur,ep)*dur; //durata del numero di episodi che posso guardare
            ep-=min(rem_time/dur,ep); //rimuovo gli episodi che ho visto 
            rem_time-=temp; //sottraggo il tempo impiegato per guardare questi episodi
        }
        if(ep==0) //se non ho più episodi passo alla prossima serie
            continue;

        int ep_day=M/dur; //ep che posso vedere in un giorno 
        int days=ep/ep_day; //giorni necessari per finire la serie 
        ep%=ep_day; //calcolo se mi serve un giorno in più per finire la serie (la divisione era approssimata per difetto
        if(ep){ //se mi serve un altro giorno
            tot_days++;
            rem_time=M-ep*dur;
        }
        else
            rem_time=M-ep_day*dur;
        
        tot_days+=days;
    }
    cout<<tot_days<<' '<<rem_time;

    return 0;
}
