#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

bool Comparator(pii& a,pii& b) {
    if(a.first==b.first)
        return a.second<b.second;
    return a.first>b.first;
}

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int n,d;
    cin>>n>>d;
int ans=0;
vector<pii>v(n);
    for(int i=0;i<n;i++){
        pii temp;
        cin>>temp.first>>temp.second;
        if(temp.second==-1) //se non ha una scadenza precisa si può leggere fino all'ultimo giorno disponibile
            v[i]={temp.first,d-1};
        else
            v[i]={temp.first,temp.second};
    }
    sort(v.begin(),v.end(),Comparator);
set<int>giorni;
    for(int i=0;i<d;i++) //inserisco i giorni in cui si può leggere
        giorni.insert(-i); //li inserisco negandoli in modo da poter usare lower bound al contrario (mi serve un giorno <= alla scadenza)
    for(int i=0;i<n;i++){
        auto it=giorni.lower_bound(-v[i].second);
        if(it!=giorni.end()){
            ans+=v[i].first;
            giorni.erase(it);
        }
    }
    cout<<ans;

    return 0;
}