#include <iostream>
using namespace std;

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
long long N;
    cin>>N;
    cout<<N*(N-1)/4.0;
    return 0;
}