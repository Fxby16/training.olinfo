#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
int N,D,H=0;
    cin>>N>>D;
vector<pii>galli(N);
priority_queue<int>usciti;

    for(int i=0;i<N;i++){
        cin>>galli[i].first>>galli[i].second;
        H+=galli[i].first;
    }
    
    sort(begin(galli),end(galli),[](pii a,pii b){ return (a.first+a.second)<(b.first+b.second); }); //ordino i galli in ordine crescente in base alla somma tra la loro altezza e la lunghezza delle braccia
    
    for(int i=0;i<N;i++){ //cerco di far uscire i galli a partire da quello più piccolo
        if(H+galli[i].second>=D){ //se il gallo i allungando le braccia riesce ad uscire lo fa
            usciti.push(galli[i].first);
            H-=galli[i].first;
        }
        else if(!usciti.empty() && H+galli[i].second+usciti.top()>=D && galli[i].first<usciti.top()){ //altrimenti se c'è un gallo già uscito che potrebbe far uscire il gallo i tornando dentro ma che è più alto li scambio
            H-=galli[i].first;
            H+=usciti.top();
            usciti.pop();
            usciti.push(galli[i].first);
        }
    }
    cout<<usciti.size();

    return 0;
}