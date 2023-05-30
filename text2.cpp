#include <bits/stdc++.h>
#pragma GCC optmize ("O3")
using namespace std;
#define ll long long
#define MAXN 100000
#define ALF 'z'-'a'+1

vector<string>s(MAXN);
vector<vector<int>>dist(MAXN,vector<int>(ALF,0));

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
int N,K;
int curr=INT_MAX,index;
int distt;
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>s[i];
        for(int j=0;j<s[i].length();j++) //per ogni indice mi salvo che caratteri ho trovato in tutte le stringhe
            dist[j][s[i][j]-'a']++;
    }
    for(int i=0;i<N;i++){
        distt=0;
        for(int j=0;j<s[i].length();j++){
            distt+=(N-dist[j][s[i][j]-'a']-1); //la distanza equivale al numero di stringhe-il numero di stringhe che alla posizione j ha lo stesso carattere-1 che è la stringa corrente
        }
        if(distt<curr){ //se ho trovato una distanza minore la aggiorno
            curr=distt;
            index=i;
        }
    }
    cout<<index;

    return 0;
}
