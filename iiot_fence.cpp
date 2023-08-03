#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
#define ll long long
#define pll pair<ll,ll>

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int N;
    cin>>N;
vector<ll>v(N);
    for(auto &i:v)
        cin>>i;

vector<pll>ans;
    ans.push_back({v[0],0});
    ans.push_back({v[1],1});
    for(int i=2;i<N;i++){  
        while(ans.size()>1 && v[i]>=ans[ans.size()-1].first && ans[ans.size()-2].first>=ans[ans.size()-1].first) //se rimuovendo l'ultimo paletto ottengo un risultato migliore, lo rimuovo
            ans.pop_back();
        ans.push_back({v[i],i}); //inserisco il nuovo paletto
    }
    ll ans_=0;
    for(int i=1;i<ans.size();i++) //calcolo la robustezza massima
        ans_+=(ans[i].second-ans[i-1].second)*min(ans[i].first,ans[i-1].first);

    cout<<ans_;


    return 0;
}