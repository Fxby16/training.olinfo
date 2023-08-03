#include <bits/stdc++.h>
using namespace std;

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int rows,cols;
    cin>>rows>>cols;
vector<vector<int>>m(rows,vector<int>(cols));
    if(rows%4==0){
        cout<<cols*(rows/4)<<'\n';
        int pezzo=0;
        for(int i=0;i<cols;i++)
            for(int j=0;j<rows;j++){
                m[j][i]=pezzo;
                if(!((j+1)%4))
                    pezzo++;
            }
    }
    else if(cols%4==0){
        cout<<rows*(cols/4)<<'\n';
        int pezzo=0;
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++){
                m[i][j]=pezzo;
                if(!((j+1)%4))
                    pezzo++;
            }
    }
    else if(cols%2==0 && rows%2==0){
        cout<<(cols/2)*(rows/2)<<'\n';
        int pezzo=0;
        for(int i=0;i<rows;i+=2)
            for(int j=0;j<cols;j+=2,pezzo++){
                m[i][j]=pezzo;
                m[i][j+1]=pezzo;
                m[i+1][j]=pezzo;
                m[i+1][j+1]=pezzo;
            }
    }
    else{
        cout<<-1;
        return 0;
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++)
            cout<<m[i][j]<<' ';
        cout<<'\n';
    }

    return 0;
}