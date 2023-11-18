#include <bits/stdc++.h>
using namespace std;

enum par{
    APERTA,CHIUSA
};

int main(){
ios::sync_with_stdio(false);
cin.tie(0);

    int N; cin>>N;
    vector<int>v(N+1);

    for(int i=1;i<=N;i++)
        cin>>v[i];

    int sum=accumulate(begin(v),end(v),0);

    if(sum%2!=0){ //se la somma è dispari è impossibile creare una sequenza corretta
        cout<<-1<<'\n';
        return 0;
    }

    int HALF_SUM=sum/2; //perchè la sequenza sia corretta la somma deve essere sempre <= della metà della somma totale
    vector<vector<bool>>dp(N+1,vector<bool>(HALF_SUM+1,false));
    vector<vector<int>>characters(N+1,vector<int>(HALF_SUM+1,0));
    dp[0][0]=true;

    int part_sum=0;
    for(int i=0;i<N;i++){
        part_sum+=v[i];
        for(int j=0;j<=min(part_sum,HALF_SUM);j++){
            if(dp[i][j]){
                if(j+v[i+1]<=HALF_SUM){ //posso aprire le parentesi
                    dp[i+1][j+v[i+1]]=true;
                    characters[i+1][j+v[i+1]]=APERTA;
                }
                if(j-v[i+1]>=0){ //posso chiudere le parentesi
                    dp[i+1][j-v[i+1]]=true;
                    characters[i+1][j-v[i+1]]=CHIUSA;
                }
            }
        }
    }

    if(!dp[N][0]){ //se non posso arrivare all'indice N con la somma=0, significa che è impossibile creare una sequenza corretta
        cout<<-1;
        return 0;
    }

    string ans;
    int index=N;
    int s=0;

    while(index>0){
        char ch=(characters[index][s]==CHIUSA)?')':'(';
        for(int i=0;i<v[index];i++){
            ans.push_back(ch);
        }

        switch(ch){ //sto leggendo dal fondo, se chiudo sommo, se apro sottraggo
            case ')':
                s+=v[index];
                break;
            case '(':   
                s-=v[index];
                break;
            default:
                break;
        }

        index--;
    }

    reverse(begin(ans),end(ans)); //avendo letto dal fondo devo invertire la stringa
    cout<<ans<<'\n';

    return 0;
}