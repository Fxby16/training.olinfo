#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N,C;
ll ans=0;
vector<vector<ll>>memo(19);

void cabala(ll n,int i,ll pot,int last){
    if(i==19) //dato che N<=18, se sono arrivato alla cifra 19 mi fermo
        return;
    memo[i].push_back(n); //salvo il numero
    if(last==3){
        cabala(n+(6*pot),i+1,pot*10,6);
        cabala(n+(9*pot),i+1,pot*10,9);
    }
    if(last==6){
        cabala(n+(3*pot),i+1,pot*10,3);
        cabala(n+(9*pot),i+1,pot*10,9);
    }
    if(last==9){
        cabala(n+(6*pot),i+1,pot*10,6);
        cabala(n+(3*pot),i+1,pot*10,3);
    }
}

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
int T;
    cin>>T;
    cabala(3,1,10,3); //mi conviene calcolarmi prima tutti i numeri dato che anche avendo più test case i numeri sono sempre quelli
    cabala(6,1,10,6);
    cabala(9,1,10,9);
    for(int i=0;i<T;i++){
        ans=0;
        cin>>N>>C;
        for(int j=1;j<=N;j++) //dato che ho già i numeri mi basta scorrerli e calcolare il modulo
            for(auto it:memo[j])
                if((it%C)>ans)
                    ans=it%C;
        cout<<ans<<' ';
    }

    return 0;
}