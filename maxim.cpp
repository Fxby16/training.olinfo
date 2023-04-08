#include <bits/stdc++.h>
using namespace std;

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
int N,K,saddest=0;
    cin>>N>>K;
vector<int>v(N);
multiset<int> memo;
    for(int i=0;i<N;i++)
    {
        cin>>v[i];
        memo.insert(v[i]); //inserisco il regalo corrente
        if(i>K){
            auto it = memo.find(v[i-K-1]);
            memo.erase(it); //rimuovo il regalo che non è più visibile
        }
        saddest=max(max(abs((*memo.begin())-v[i]),abs((*memo.rbegin())-v[i])),saddest); //calcolo la differenza massima tra quella già ottenuta e il valore assoluto della diffenza tra v[i] e il massimo e il minimo nel range
    }
    cout<<saddest;

    return 0;
}