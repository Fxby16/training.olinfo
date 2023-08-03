#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

vector<int>rows0;
vector<int>rows1;
vector<int>cols0;
vector<int>cols1;

int pulisci(int N,int M,vector<string>S){
    bool a,b,c,d;
    rows0.assign(N,0);
    rows1.assign(N,0);
    cols0.assign(M,0);
    cols1.assign(M,0);
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++){
            if(S[i][j]=='0'){
                rows0[i]++;
                cols0[j]++;
            }
            else{
                rows1[i]++;
                cols1[j]++;
            }
        }
    sort(begin(rows0),end(rows0));
    sort(begin(rows1),end(rows1));
    sort(begin(cols0),end(cols0));
    sort(begin(cols1),end(cols1));

    int r1=N-1,r0=N-1,c1=M-1,c0=M-1;
    while(1){
        a=b=c=d=true;
        if(rows0[r0]==M && r0>=0){ //tolgo una riga di 0
            --N;
            --r0;
            for(int k=c0;cols0[k]>0;k--) //rimuovo da tutte le colonne con degli 0 uno 0
                cols0[k]--;
            a=false;
        }
        if(rows1[r1]==M && r1>=0){ //tolgo una riga di 1
            --N;
            --r1;
            for(int k=c1;cols1[k]>0;k--) //rimuovo da tutte le colonne con degli 1 un 1
                cols1[k]--;
            b=false;
        }
        if(cols0[c0]==N && c0>=0){ //tolgo una colonna di 0
            --M;
            --c0;
            for(int k=r0;rows0[k]>0;k--) //rimuovo da tutte le righe con degli 0 uno 0
                rows0[k]--;
            c=false;
        }
        if(cols1[c1]==N && c1>=0){ //tolgo una colonna di 0
            --M;
            --c1;
            for(int k=r1;rows1[k]>0;k--) //rimuovo da tutte le righe con degli 1 un 1
                rows1[k]--;
            d=false;
        }
        if(a && b && c && d) //se non ho apportato modifiche in questa iterazione ho finito
            break;
    }
    return N*M; //ritorno i sacchi restanti
}

int main() {
  int N, M;

  cin >> N >> M;

  vector<string> S(N);

  for(int i = 0; i < N; i++) {
    cin >> S[i];
  }

  cout << pulisci(N, M, S) << endl;

  return 0;
}
