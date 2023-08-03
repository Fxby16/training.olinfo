#include <iostream>
#pragma GCC optimize ("Ofast")
using namespace std;

int rows,cols;
int ans=0;
int area;

inline bool controlla(int m[10][10],int i,int j){
    if(m[i][j])
        return false;
    if(i>=2){
        if(m[i-1][j]&&m[i-2][j])
            return false;
        if(j>=2){
            if(m[i-1][j-1]&&m[i-2][j-2])
                return false;
        }
        if(j<=cols-3){
            if(m[i-2][j+2]&&m[i-1][j+1])
                return false;
        }
    }
    if(i<=rows-3){
        if(m[i+1][j]&&m[i+2][j])
            return false;
        if(j>=2){
            if(m[i+1][j-1]&&m[i+2][j-2])
                return false;
        }
        if(j<=cols-3){
            if(m[i+1][j+1]&&m[i+2][j+2])
                return false;
        }
    }
    if(j>=2){
        if(m[i][j-1]&&m[i][j-2])
            return false;
    }
    if(j<=cols-3){
        if(m[i][j+1]&&m[i][j+2])
            return false;
    }
    if(j>0 && j<cols-1){
        if(m[i][j-1]&&m[i][j+1])
            return false;
    }
    if(i>0 && i<rows-1){
        if(m[i-1][j]&&m[i+1][j])
            return false;
    }
    if(j>0 && i>0 && j<cols-1 && i<rows-1){
        if(m[i-1][j-1]&&m[i+1][j+1])
            return false;
        if(m[i-1][j+1]&&m[i+1][j-1])
            return false;
    }

    return true;
}


void solve(int m[10][10],int count,int i,int j){
    if(j>=cols){
        i++;
        j=0;
    }
    if(i==rows){
        if(count>ans)
            ans=count;
        return;
    }
    if((area-((i)*cols+j)+count)<=ans) //se aggiungendo il numero massimo di x possibili a quelle che ho adesso non ho un risultato migliore, non mi serve andare avanti
		    return;	
    if(controlla(m,i,j)){
        m[i][j]=1;
        solve(m,count+1,i,j+1);
        m[i][j]=0;
    }
    solve(m,count,i,j+1);
}

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
    cin>>rows>>cols;
int m[10][10];
    area=rows*cols;
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            cin>>m[i][j];

    solve(m,0,0,0);

    cout<<ans;

    return 0;
}
