#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

int K;
vector<vector<int>>adj;
vector<int>ans;
vector<int>ancestors;

void dfs(int node){
    ancestors.push_back(node);
    if(ancestors.size()>=K+1)
        ans[node]=ancestors[ancestors.size()-K-1];
    
    for(auto x:adj[node]){
        dfs(x);
    }
    ancestors.pop_back();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin>>N>>K;

    adj.resize(N);
    ans.assign(N,-1);

    for(int i=0;i<N-1;i++){
        int a,b;
        cin>>a>>b;
        adj[min(a,b)].push_back(max(a,b));
    }

    dfs(0);

    for(auto x:ans)
        cout<<x<<' ';

    cout<<'\n';

    return 0;
}