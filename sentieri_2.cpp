#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

vector<pair<int, int>> adj[105]; // adjacency list
int dist[105][105]; // distance matrix

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                dist[i][j] = INF;
            }
        }
    }
    for (int i = 0; i < a + b; i++) {
        int u, v, w;
        cin >> u >> v;
        if (i >= a) { // if the edge is bollente
            w = 1;
        } else { // if the edge is not bollente
            w = 0;
        }
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        dist[u][v] = w;
        dist[v][u] = w;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    cout << dist[1][n] << endl;
    return 0;
}
