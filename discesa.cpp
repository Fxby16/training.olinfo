#include <bits/stdc++.h>
using namespace std;

int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
    int N;
    cin>>N;

    vector<vector<int>> piramide(N,vector<int>(N));
    for (int i=0;i<N;i++) {
        for (int j=0;j<=i;j++) {
            cin>>piramide[i][j];
        }
    }

    for (int i=N-2;i>=0;i--) {
        for (int j=0;j<=i;j++) {
            piramide[i][j]+=max(piramide[i+1][j],piramide[i+1][j+1]);
        }
    }

    cout<<piramide[0][0];


    return 0;
}