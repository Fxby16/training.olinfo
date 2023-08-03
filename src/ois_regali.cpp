#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> a, vector<int> b)
{
    for (int i=0;i<a.size();i++)
        if (a[i]<b[i])
            return true;
        else if (a[i]>b[i])
            return false;

    return false;
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);    
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
    int N,Q,ans=0,temp;
    cin>>N>>Q;
    vector<vector<int>>G(N,vector<int>(Q));

    for(int i=0;i<N;i++){
        for (int j=0;j<Q;j++)
            cin>>G[i][j];
    }
    sort(G.begin(), G.end(),comp);
    for(int i=0;i<N-1;i++){
        temp=0;
        for(int j=0;j<Q;j++)
        {
            if(G[i][j]==G[i+1][j])
                temp++;
            else
                break;
        }
        ans=max(ans,temp);
    }
    cout<<ans;
    return 0;
}
