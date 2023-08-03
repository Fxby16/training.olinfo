#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long

long long costruisci(int N, int M, vector<long long>& H, vector<int>& A,vector<int>& B, vector<int>& C){
ll ans=0;
    vector<vector<pair<int,int>>>adj(N);
    for(int i=0;i<M;++i) {
        adj[A[i]].push_back({B[i],C[i]});
    }
    
    priority_queue<pair<ll,ll>>Q;
    
    for(int i=0;i<N;i++)
        Q.push({-H[i],i});

    while(!Q.empty()){
        ll dis=-Q.top().first;
        ll node=Q.top().second;
        Q.pop();
        for(auto [to,add]:adj[node]){
            if(H[to]>add+dis){
                H[to]=add+dis;
                Q.push({-H[to],to});
            }
        }
    }
    for(auto it:H)
        ans+=it;

    return ans;
}

//grader
int main() {
    // Input da file:
    // freopen("input.txt", "r", stdin);

    // Output su file:
    // freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<long long> h(n);
    vector<int> a(m), b(m), c(m);

    for(size_t i = 0; i < n; i++) {
        cin >> h[i];
    }
    for(size_t j = 0; j < m; j++) {
        cin >> a[j] >> b[j] >> c[j];
    }
    cout << costruisci(n, m, h, a, b, c) << endl;
    return 0;
}
