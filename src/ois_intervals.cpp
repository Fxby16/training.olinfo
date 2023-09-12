#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

using pii=pair<int,int>;

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int N;
    cin>>N;

vector<pii>v(N);
    for(auto &[a,b]:v)
        cin>>a>>b;

    sort(v.begin(),v.end(),[](pii &a,pii &b){ return a.second<b.second; });

multiset<int>shows;
    for(auto &[a,b]:v){
        if(shows.find(a)==shows.end())
            shows.insert(b);
        else{
            shows.erase(shows.find(a));
            shows.insert(b);
        }
    }

    cout<<shows.size()<<'\n';

    return 0;
}