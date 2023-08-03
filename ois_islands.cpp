#include <iostream>
#include <vector>
#pragma GCC optimize ("O3")
using namespace std;
#define MAXN 1000

int rows,cols,ans=0;
vector<vector<short>>m(MAXN,vector<short>(MAXN));
vector<vector<bool>>visited(MAXN,vector<bool>(MAXN,false));
bool x;
void islands(int i,int j){
    visited[i][j]=true;
    if(i==0 || i==rows-1 || j==0 || j==cols-1)
        x=true;
    if(j>0 && !visited[i][j-1] && m[i][j-1])
        islands(i,j-1);
    if(i>0 && !visited[i-1][j] && m[i-1][j])
        islands(i-1,j);
    if(i<rows-1 && !visited[i+1][j] && m[i+1][j])
        islands(i+1,j);
    if(j<cols-1 && !visited[i][j+1] && m[i][j+1])
        islands(i,j+1);
}

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
    cin>>rows>>cols;
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            cin>>m[i][j];
    
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++){
            if(!visited[i][j] && m[i][j]){
                x=false;
                if(i==0 || i==rows-1 || j==0 || j==cols-1)
                    x=true;
                islands(i,j);
                if(!x)
                    ans++;
            }
        }
    cout<<ans;

    return 0;
}