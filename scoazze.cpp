#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
#define ll long long

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int n,q,a,b;
ll ans=0;
    cin>>n>>q;

vector<int>cap(n);
vector<int>bins(n,0);
    for(auto &i:cap)
        cin>>i;
    while(q--){
        cin>>a>>b;
        if(bins[a]+b>cap[a]){
            ans+=cap[a]-bins[a];
            bins[a]=b;
        }
        else
            bins[a]+=b;
    }
    for(int i=0;i<n;i++)
        if(bins[i]>0)    
            ans+=cap[i]-bins[i];

    cout<<ans;

    return 0;
}