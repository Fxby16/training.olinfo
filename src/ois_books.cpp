#include <iostream>
using namespace std;

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int N;
    cin>>N;

    for(int i=0;i<N/2;i++) //reverse first half (cost 0)
        cout<<"1 0 1\n";

    cout<<(N+1)/2<<" 0 1\n"; //move second half on the top of the first (cost 1)

    for(int i=0;i<(N+1)/2;i++) //reverse the second half (cost 0)
        cout<<"1 1 0\n";

    cout<<(N+1)/2<<" 0 1\n"; //move the first half on the top of the second

    return 0;
}