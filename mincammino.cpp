#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define MAXN 300000
vector<vector<pair<int,int>>>adj(MAXN+1);

void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int>P, vector<int>& D)
{
    for(int i=0;i<N;i++)
        D[i]=INF;

    for(int i=0;i<M;i++)
        adj[X[i]].push_back({Y[i],P[i]});

int start=0;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
Q.push({start,0});
D[start]=0;
    while(!Q.empty())
    {
        int temp1=Q.top().first;
        int temp2=Q.top().second;
        Q.pop();
        if(temp2>D[temp1])
            continue;
        for(auto it:adj[temp1])
        {
            if(D[it.first]>(it.second+temp2))
            {
                D[it.first]=it.second+temp2;
                Q.push({it.first,D[it.first]});
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        if(D[i]==INF)
            D[i]=-1;
    }
}

int main() {
    ios::sync_with_stdio(false);

    // Uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    // Reading input
    int N, M;
    cin >> N >> M;

    vector<int> X(M), Y(M), P(M), D(N);
    for (int i = 0; i < M; i++) {
        cin >> X[i] >> Y[i] >> P[i];
    }

    // Calling functions
    mincammino(N, M, move(X), move(Y), move(P), D);

    // Writing output
    for(int d : D) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}