#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAXN 10

int ans=0,N;
void cat(vector<pii>a,pii card,int N)
{
int count=1;
    for(int i=1;i<N;i++)
    {
        if(a[i].first==card.first)
        {
            count++;
            card.first=a[i].second;
        }
        else if(a[i].second==card.first)
        {
            count++;
            card.first=a[i].first;
        }
        else if(a[i].first==card.second)
        {
            count++;
            card.second=a[i].second;
        }
        else if(a[i].second==card.second)
        {
            count++;
            card.second=a[i].first;
        }
    }
    ans=max(ans,count); //aggiorno il risultato se ho trovato una sequenza migliore
}

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
    cin>>N;
vector<pii>a(N);
    for(int i=0;i<N;i++)
        cin>>a[i].first>>a[i].second;
    
    while(next_permutation(a.begin(),a.end())) //provo tutte le combinazioni
        cat(a,a[0],N);

    cout<<ans;

    return 0;
}