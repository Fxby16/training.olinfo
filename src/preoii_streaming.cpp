#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using pll=pair<ll,ll>;

long long bfs(int N, long long K, std::vector<int> P, std::vector<int> F){
vector<pll>v(N);
    for(int i=0;i<N;i++)
        v[i]=make_pair(P[i],F[i]);

    sort(begin(v),end(v),greater<pll>());

ll ans=0;
ll cost=0;
priority_queue<ll>Q;
    for(auto [p,f]:v){
        Q.push(f);
        cost+=f;
        while((cost>K || Q.top()>p) && !Q.empty()){
            cost-=Q.top();
            Q.pop();
        }
        ans=max(ans,p*(ll)Q.size()-cost);
    }
    return ans;
}