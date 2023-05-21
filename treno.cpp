#include <iostream>
using namespace std;

string ans="";
int k=0;
void solve(int n){
    if(n>4){    
        ans+=to_string(n)+' '+to_string(n*2+1)+'\n';
        ans+=to_string(n*2-1)+' '+to_string(n)+'\n';
        k+=2;
        solve(n-1);
        ans+=to_string(2*n+1)+' '+to_string(2*n-1)+'\n';
        k++;
    }
    else if(n==3){
        ans+="2 7\n6 2\n4 6\n7 4\n";
        k+=4;
    }
    else if(n==4){
        ans+="4 9\n6 4\n2 6\n5 2\n9 5\n";
        k+=5;
    }
}

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
int N;
    cin>>N;
    solve(N);
    cout<<k<<' '<<N<<'\n'<<ans;

    return 0;
}