#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
using ll=long long;

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int N,R,T,L;
vector<ll>semafori;
ll ans=LONG_LONG_MAX;
    cin>>N>>R>>T>>L;
    semafori.resize(N);

    for(auto &i:semafori)
        cin>>i;
    semafori.push_back(L);
vector<vector<ll>>m(N+1,vector<ll>(R+1,LONG_LONG_MAX));

m[0][R]=semafori[0]; //si parte dal semaforo 0 potendo saltare al massimo R semafori

    for(int i=1;i<N+1;i++)
        for(int j=0;j<R+1;j++){
            if(m[i-1][j]==LONG_LONG_MAX) //se non ho calcolato m[i-1][j] non mi serve calcolare nemmeno m[i][j]
                continue;
            if((m[i-1][j]/T)%2==0) //il semaforo è verde, passo senza dover fare nulla
                m[i][j]=min(m[i][j],m[i-1][j]+semafori[i]-semafori[i-1]);
            else{ //il semaforo è rosso
                m[i][j]=min(m[i][j],m[i-1][j]+semafori[i]-semafori[i-1]+T-m[i-1][j]%T); //mi fermo al semaforo e aspetto che diventi verde
                if(j>0)
                    m[i][j-1]=min(m[i][j-1],m[i-1][j]+semafori[i]-semafori[i-1]); //non mi fermo al semaforo, posso saltare al massimo altri j-1 semafori 
            }
        }
    
    for(int i=0;i<R+1;i++) //salvo il tempo minore
        ans=min(ans,m[N][i]);
    cout<<ans<<'\n';

    return 0;
}