#include <bits/stdc++.h>
using namespace std;

uint64_t Power(uint64_t exponent){
    if(exponent==0)
        return 1;
    return 1LL<<exponent;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    uint64_t Q,N;

    cin>>Q;

    while(Q--){
        cin>>N;

        cout<<(N-Power(log2(N)))*2+1<<endl;
    }

    return 0;
}