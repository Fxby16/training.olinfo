#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
using ll=long long;

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int N;
ll M,L;
    cin>>N>>M>>L;
map<ll,int>val;
int ans=INT_MAX;
    for(int i=0;i<N;i++){
        ll n;
        cin>>n;
        val[max(0LL,n-M)]++; //inizio intervallo
        if(n+M<L)
            val[n+M]--; //fine intervallo, solo se finisce prima di L
    }
int curr=0;
    if(val.begin()->first>0){ //se D[0]-M>0 allora ci si può nascondere all'inizio della strada
        cout<<0<<'\n';
        return 0;
    }
    for(auto i:val){ //itero sugli intervalli
        curr+=i.second;
        ans=min(ans,curr); //controllo se ho trovato una soluzione migliore
    }

    cout<<ans<<'\n';

    return 0;
}